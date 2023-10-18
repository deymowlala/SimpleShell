#include "shell.h"

/**
 * cles_info - initializes information and clear it
 * @infore: struct address to create a new varibles 
 */
void cles_info(info_t *infore)
{
	infore->arg = NULL;
	infore->argv = NULL;
	infore->path = NULL;
	infore->argc = 0;
}
//-------------------------------------------------------------------------
/**
 * st_infor - initializes info_t struct
 * @infor: struct address
 * @amv: argument vector
 */
void st_infor(info_t *infor, char **amv)
{
    int i = 0;

    infor->fname = amv[0];
    if (infor->arg)
    {
        infor->argv = strtow(infor->arg, " \t");
        if (!infor->argv)
        {
            infor->argv = malloc(sizeof(char *) * 2);
            if (infor->argv)
            {
                infor->argv[0] = _strdup(infor->arg);
                infor->argv[1] = NULL;
            }
        }
        
        M= 0;
        while (infor->argv && infor->argv[M])
        {
            M++;
        }
        infor->argc = M;

        replace_alias(infor);
        replace_vars(infor);
    }
}
//-------------------------------------------------------------------
/**
 * fre_infor - frees info_t struct fields
 * @infor: information type struct address
 * @alfre: if freeing all fields true 
 */
void fre_infor(info_t *infor, int allfre)
{
	ffree(infor->argv);
	infor->argv = NULL;
	infor->path = NULL;
	if (allfre)
	{
		if (!infor->cmd_buf)
			free(info->arg);
		if (infor->env)
			free_list(&(info->env));
		if (infor->history)
			free_list(&(info->history));
		if (infor->alias)
			free_list(&(info->alias));
		ffree(infor->environ);
			infor->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (infor->readfd > 2)
			close(infor->readfd);
		_putchar(BUF_FLUSH);
	}
}
