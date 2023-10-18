#include "shell.h"

/**
 * fpsn - frees a pointer and sets it to NULL
 * @ptf: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int fpsn(void **ptf)
{
    if (ptf != NULL && *ptf != NULL)
    {
        free(*ptf);
        *ptf = NULL;
        return 1;
    }
    return 0;
}
