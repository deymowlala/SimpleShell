#include "shell.h"

/**
 * get_envir - returns the string array copy of our environ
 * @infor: Structure containing potential arguments. Used to maintain constant function prototype.
 * Return: Always 0
 */
char **get_envir(info_t *infor)
{
	if (!infor->environ || infor->env_changed)
	{
		infor->environ = list_to_strings(infor->env);
		infor->env_changed = 0;
	}

	return (infor->environ);
}
//------------------------------------------------------------------------
/**
 * _unsetent - Remove an environment variable
 * @infor: Structure containing potential arguments. Used to maintain constant function prototype.
 * @varprop: the string env var property
 *  Return: 1 on delete, 0 otherwise
 */
int _unsetent(info_t *infor, char *varprop)
{
    list_t *node = infor->env;
    size_t w = 0;
    char *p;

    if (!node || !varprop)
        return 0;

    for (; node != NULL; node = node->next, w++)
    {
        p = starts_with(node->str, varprop);
        if (p && *p == '=')
        {
            infor->env_changed = delete_node_at_index(&(infor->env), w);
            w = 0;
            node = infor->env;
        }
    }

    return info->env_changed;
}
//------------------------------------------------------------------------
/**
 * _setent - Initialize a new environment variable, or modify an existing one
 * @infor: Structure containing potential arguments. Used to maintain constant function prototype.
 * @varprop: the string env var property
 * @valuevar: the string env var value
 *  Return: Always 0
 */
int _setent(info_t *infor, char *varprop, char *valuevar)
{
    char *buf = NULL;
    list_t *node;
    char *p;

    if (!varprop || !valuevar)
        return 0;

    buf = malloc(_strlen(var) + _strlen(value) + 2);
    if (!buf)
        return 1;
    _strcpy(buf, var);
    _strcat(buf, "=");
    _strcat(buf, value);
    node = infor->env;

    for (; node != NULL; node = node->next)
    {
        p = starts_with(node->str, var);
        if (p && *p == '=')
        {
            free(node->str);
            node->str = buf;
            infor->env_changed = 1;
            return 0;
        }
    }

    add_node_end(&(info->env), buf, 0);
    free(buf);
    info->env_changed = 1;
    return 0; //Finally, the function frees the memory allocated for buf and returns 0.
}
