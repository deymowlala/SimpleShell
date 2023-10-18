#include "shell.h"

/**
 * is_cmdo - determines if a file is an executable command
 * @infor: the info struct
 * @pather: path to the file
 * Return: 1 if true, 0 otherwise
 */
int is_cmdo(info_t *infor, char *pather)
{
    struct stat st;

    if (!path || stat(path, &st) != 0)
        return 0;

    return S_ISREG(st.st_mode);
}
//------------------------------------------------------------------------------
/**
 * dp_char - duplicates characters
 * @strpaht: the PATH string
 * @srt:  index that starts
 * @end: index that will stop and end
 * Return: A new buffer pointer's
 */
char *dp_char(char *strpaht, int srt, int end)
{
    int length = end - srt;
    char *buf = malloc((length + 1) * sizeof(char));
    int k = 0;

    if (!buf)
        return NULL;

    for (int i = srt; i < end; i++)
    {
        if (strpaht[i] != ':')
            buf[k++] = strpaht[i];
    }

    buf[k] = '\0';
    return buf;
}
//------------------------------------------------------------------------------
/**
 * find_path - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
    if (!pathstr)
        return NULL;

    if (strlen(cmd) > 2 && strncmp(cmd, "./", 2) == 0)
    {
        if (is_cmd(info, cmd))
            return cmd;
    }

    int curr_pos = 0;
    int i = 0;
    char *path = NULL;

    while (1)
    {
        if (!pathstr[i] || pathstr[i] == ':')
        {
            int path_length = i - curr_pos;
            path = malloc((path_length + strlen(cmd) + 2) * sizeof(char));

            if (!path)
                return NULL;

            strncpy(path, &pathstr[curr_pos], path_length);
            path[path_length] = '\0';

            if (*path)
                strcat(path, "/");
            strcat(path, cmd);

            if (is_cmd(info, path))
                return path;

            if (!pathstr[i])
                break;

            curr_pos = i + 1;
        }
        i++;
    }

    return NULL;
}
