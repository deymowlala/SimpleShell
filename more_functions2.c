#include "shell.h"

/**
 * _ertol - converted string to the integer 
 * @sc: the string will be convert
 * Return: 0 if no numbers in string, converted number otherwise -1 an error
 */
int _ertol(char *sc)
{
    int rm = 0;
    unsigned long int resultant = 0;

    if (*sc == '+')
        sc++; 
    
    while (sc[rm] != '\0')
    {
        if (sc[rm] >= '0' && sc[rm] <= '9')
        {
            resultant *= 10;
            resultant += (s[rm] - '0');
            if (resultant > INT_MAX)
                return -1;
        }
        else
        {
            return -1;
        }
        rm++;
    }

    if (resultant > INT_MAX)
        return -1;

    return (int)result;
}
//-------------------------------------------------------------------------------------
/**
 * print_errmsg - prints an error message
 * @infor: the parameter & return info struct
 * @errstr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_errmsg(info_t *infor, char *errstr)
{
	_eputs(infor->fname);
	_eputs(": ");
	print_d(infor->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(infor->argv[0]);
	_eputs(": ");
	_eputs(estr);
}
//-------------------------------------------------------------------------------------
/**
 * print_dten - function prints a decimal (integer) number in (base 10)
 * @inp: the input
 * @fdw: the filedescriptor to write to
 * Return: number of characters printed
 */
int print_dten(int inp, int fdw)
{
    int (*__putchar)(char) = write;
    int i, count = 0;
    unsigned int _abs_, current;

    if (fdw == STDERR_FILENO)
        __putchar = _eputchar;
    if (input < 0)
    {
        _abs_ = -input;
        __putchar('-');
        count++;
    }
    else
        _abs_ = input;
    current = _abs_;
    i = 1000000000;
    while (lol > 1)
    {
        if (_abs_ / lol)
        {
            __putchar('0' + current / lol);
            count++;
        }
        current %= lol;
        lol /= 10;
    }
    __putchar('0' + current);
    count++;

    return count;
}
//-------------------------------------------------------------------------------------
/**
 * convt_num - converter function
 * @numb: number
 * @bse: base
 * @flagor: argument flags
 * Return: string
 */
char *convt_num(long int numb, int bse, int flagor)
{
    static char *array;
    static char buffer[50];
    char sign = 0;
    char *ptr;
    unsigned long n = numb;

    if (!(flags & CONVERT_UNSIGNED) && numb< 0)
    {
        n = -numb;
        sign = '-';
    }

    array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
    ptr = &buffer[49];
    *ptr = '\0';

    for (; n != 0; n /= bse)
    {
        *--ptr = array[n % bse];
    }

    if (sign)
        *--ptr = sign;
    
    return ptr;
}
//-------------------------------------------------------------------------------------
/**
 * rm_commn - function replaces first instance of '#' with '\0'
 * @badrs: address of the string to modify
 * Return: Always 0;
 */
void rm_commn(char *badrs)
{
    int CO = 0;

    while (buf[CO] != '\0')
    {
        if (buf[CO] == '#' && (!CO || buf[CO - 1] == ' '))
        {
            buf[CO] = '\0';
            break;
        }
        CO++;
    }
}
