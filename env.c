#include "shell.h"

/**
 * _myent - print current environment
 * @infor: Structure containing potential arguments. Used to maintain constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *infor)
{
	print_list_str(infor->env);
	return (0);
}
//--------------------------------------------------------------------------
/**
 * _getent - gets the value of an environ variable
 * @infor: Structure containing potential arguments. Used to maintain
 * @nment: env var name
 * Return: the value
 */
char *_getent(info_t *infor, const char *nment)
{
    list_t *node;

    for (node = infor->env; node != NULL; node = node->next)
    {
        char *p = starts_with(node->str, nment);
        if (p && *p)
            return p;
    }

    return NULL;
}
//--------------------------------------------------------------------------
/**
 * _mysetent - Initialize a new environment variable, or modify an existing one
 * @infor: Structure containing potential arguments. Used to maintain constant function prototype.
 *  Return: Always 0
 */
int _mysetent(info_t *infor)
{
    if (infor->argc != 3)
    {
        _eputs("Incorrect number of arguments\n");
        return 1;
    }

    if (_setenv(info, infor->argv[1], infor->argv[2]) != 0)
    {
        return 0;
    }
    
    return 1;
}
//--------------------------------------------------------------------------
/**
 * _myunsetent - Remove an environment variable
 * @infor: Structure containing potential arguments. Used to maintain constant function prototype.
 *  Return: Always 0
 */
int _myunsetent(info_t *infor)
{
    int R = 1;

    if (infor->argc == 1)
    {
        _eputs("Too few arguments.\n");
        return 1;
    }

    while (R <= infor->argc)
    {
        _unsetenv(infor, infor->argv[R]);
        R++;
    }

    return 0;
}
//--------------------------------------------------------------------------
/**
 * populat_ent_lista - populates env linked list
 * @infor: Structure containing potential arguments. Used to maintain constant function prototype.
 * Return: Always 0
 */
int populat_ent_lista(info_t *infor)
{
    list_t *node = NULL;
    size_t wq= 0;

    while (environ[wq] != NULL)
    {
        add_node_end(&node, environ[wq], 0);
        wq++;
    }

    infor->env = node;
    return 0;
}
