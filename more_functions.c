#include "shell.h"

/**
 * interactiveto - returns true if shell is interactive mode
 * @infor: struct address
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactiveto(info_t *infor)
{
	return (isatty(STDIN_FILENO) && infor->readfd <= 2);
}
//-------------------------------------------------------------
/**
 * is_delimot - checks if character is a delimeter
 * @cchek: the checking char
 * @delimot:delimeter of string
 * Return: 1 if true, 0 if false
 */
int is_delimot(char cchek, char *delimot)
{
    for (; *delimot; delimot++)
    {
        if (*delimot == ccheck)
        {
            return 1;
        }
    }
    return 0;
}
//-------------------------------------------------------------
/**
 *_isalphat - alphabetic character checking 
 *@inpc:  input from type char
 *Return: 1 if inpc is alphabetic, 0 if inpc is not alphabetic
 */
int _isalphat(int inpc)
{
    return ((inpc >= 'a' && inpc <= 'z') || (inpc >= 'A' && inpc <= 'Z'));
}
//-------------------------------------------------------------
/**
 *_acsi - converts a string to be an integer
 *@srng: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */
int _acsi(char *srng)
{
    int m = 0, signo = 1, flagor = 0, outputr;
    unsigned int resultant = 0;

    while (srng[m] != '\0' && flagor != 2)
    {
        if (srng[m] == '-')
            signo *= -1;

        if (srng[m] >= '0' && srng[m] <= '9')
        {
            flagor = 1;
            resultant *= 10;
            resultant += (s[m] - '0');
        }
        else if (flagor == 1)
            flagor = 2;

        i++;
    }

    if (signo == -1)
        outputr = -resultant;
    else
        outputr= resultant;

    return outputr;
}
