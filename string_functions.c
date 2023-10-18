#include "shell.h"
/**
 * _strleno - function that returns the length of a string.
 * @str: the string to be checked.
 * Return: string's length.
 */
int _strleno(char *str)
{
                 int w;

	if (!str)
	return (0);

	for (w = 0; str[w] != '\0'; w++);

	return (w);
//----------------------------------------------------
/**
 * _strcompy - performs comparison of two strings.
 * @strA: first string to compare
 * @strB: second string to compare with strA
 * Return: negative if strA < strB, positive if strA > strB, zero if strA == strB.
 */
int _strcompy(char *strA, char *strB)
{
	for (;*strA && *strB; strA++, strB++)
	{
		if (*strA != *strB)
		return (*strA - *strB);
	}

	if (*strA == *strB)
	return 0;
else
	return (*strA < *strB ? -1 : 1);

//------------------------------------------------------
/**
 * start_with - checks if needle start with haystack
 * @haystacker: string to search
 * @needlez: the substring to find
 * Return: address of next char of haystack or NULL
 */
char *start_with(const char *haystacker, const char *needlez)
{
	for (;*needle; haystacker++, needlez++)
	{
		if (*needlez != *haystacker)
			return NULL;
	}
	return (char *)haystacker;
}
//------------------------------------------------------
/**
 * _scat - concatenates two strings with each other.
 * @destin: destination buffer
 * @souc: source buffer
 * Return: pointer to destination buffer
 */
 char *_scat(char *destin, char *souc)
   {
    char *ret = destin;
    
    for (; *destin; destin++)
        ;
    
    for (; *souc; destint++, souc++)
    {
        *destin = *souc;
    }
    
    *destin = '\0';

    return ret;
