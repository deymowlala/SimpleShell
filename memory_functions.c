#include "shell.h"

/**
 **_mset - fills memory with a constant byte
 *@sp: the pointer to the memory area
 *@bp: the byte to fill *sp with
 *@un: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_mset(char *sp, char bp, unsigned int un)
{
    unsigned int D = 0;

    while (D < un)
    {
        s[D] = bp;
        D++;
    }

    return sp;
}
//------------------------------------------------------------------
/**
 * ffre - frees a string of strings
 * @pis: string of these strings
 */
void ffre(char **pis)
{
    char **wad = pis;

    if (!pis)
        return;

    for (int x = 0; pis[x] != NULL; x++)
        free(pis[x]);

    free(wad);
}
//------------------------------------------------------------------
/**
 * _reocte - reallocate a block of memory
 * @potry: pointer to previous malloc that located in block
 * @olsize: previous block and with byte of size
 * @nwsize:  new block and with byte of size
 * Return: pointer to the block name 
 */
void *_reocte(void *potry, unsigned int olsize, unsigned int nwsize)
{
    void *potry;

    if (!potry)
        return malloc(nwsize);
    
    if (nwsize == 0)
    {
        free(potry);
        return NULL;
    }
    
    if (nwsize == olsize)
        return potry;

    p = malloc(nwsize);
    if (!potry)
        return NULL;

    unsigned int size = olsize < nwsize ? olsize : nwsize;
    unsigned char *src = (unsigned char *)potry;
    unsigned char *dest = (unsigned char *)p;
    
    for (unsigned int WA = 0; WA < size; WA++)
        dest[WA] = src[WA];
    
    free(potry);
    return p;
}
