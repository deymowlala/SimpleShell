#include "shell.h"
/**
 * _strcp - string that will be copied
 * @destin: destination string be copied to
 * @souc: source string
 * @amo: the amount of characters 
 * Return: string which are concatenated 
 */
char *_strcp (char *destin, char *souc, int amo)
{
	int i;
	char *s = destin;

	for (i = 0; souc[i] != '\0' && i < amo - 1; i++)
	{
		destin[i] = souc[i];
	}

	if (i < amo)
	{
		int j;
		for (j = i; j < amo; j++)
		{
		destin[j] = '\0';
		}
	}

	return s;
}
//-------------------------------------------------------------------

/**
 **_strenocata - concatenates two strings
 *@destin: first string will be concatenate
 *@souc: second string will be concatenate
 *@amo: the amount of bytes that maximum to be used
 *Return: concatenated two of strings
 */
char *_strenocata(char *destin, char *souc, int amo)
{
	int i;
	char *s = destin;

	for (i = 0; destin[i] != '\0'; i++)
		;

	int j;
	for (j = 0; souc[j] != '\0' && j < n; j++)
	{
		destin[i] = souc[j];
		i++;
	}

	if (j < n)
		destin[i] = '\0';

	return s;
}
//-------------------------------------------------------------------
/**
 **_locha - locates a character in a string
 *@sp: the string to be parsed
 *@cr: the character is looking for
 *Return: (s) a pointer to the memory area s
 */
char *_locha(char *sp, char cr)
{
	for (; *s != '\0'; s++)
	{
		if (*sp == cr)
			return sp;
	}

	return NULL;
}
