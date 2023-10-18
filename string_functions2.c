#include "shell.h"

/**
 * _scpy - copying all string
 * @destin: destination
 * @souc:  source
 * return: pointer to  the destination
 */
char *_scpy(char *destin, char *souc)
{
	if (destin == souc || souc == 0)
	return destin;

	int w;

	for (w = 0; souc[w]; w++)
	{
	   destin[w] = souc[w];
	}

	destin[i] = '\0';

	return destin;
}
//------------------------------------------------------
/**
 * _strduplo - string duplications
 * @strg: the string that will duplicate
 * return: duplicated string by pointer
 */
char *_strduplo(const char *strg)
{
	if (strg == NULL)
	return NULL;

	int length = 0;
	const char *ptr = strg;

	while (*ptr++)
	length++;

	char *ret = malloc(sizeof(char) * (length + 1));

	if (!ret)
	return NULL;

	int z ;
	for (z = 0; z < length; z++)
	ret[i] = strg[z];

	ret[length] = '\0';

	return ret;
}
//------------------------------------------------------
/**
 * _prs - prints an input string
 * @strg: the string to be printed
 * return: Nothing would be return
 */
void _prs(char *strg)
{
	if (!strg)
	return;

	int w;

	for (w = 0; strg[i] != '\0'; w++)
	{
		_putchar(strg[w]);
	}
}
//------------------------------------------------------
/**
 * _putch - writes the character c
 * @chara: The character would be print 
 * return: On success 1
 */
int _putch(char chara)
{
	static int v;
	static chara buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, v);
		v = 0;
	}
	else
	{
		buf[v++] = c;
	}

	return 1;
}
