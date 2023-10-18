#include "shell.h"

/**
 * **strtwp - splitting a string into many of words.
 * @stc:  input of string
 * @deli:  delimeter of string
 * return: a pointer to an array of strings on succuss, or NULL on a failure
 */

char **strtwp(char *stc, char *deli)
{
	int i = 0, j = 0, k, m, numwords = 0;
	char **s;

	if (stc == NULL || stc[0] == '\0')
		return NULL;

	if (deli == NULL)
		deli= " ";

	while (stc[i] != '\0')
	{
		if (!is_delim(stc[i], d) && (is_delim(str[i + 1], d) || str[i + 1] == '\0'))
		numwords++;
		i++;
	}

	if (numwords == 0)
		return NULL;

	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return NULL;

	i = 0;
	j = 0;
	while (j < numwords)
	{
		while (is_delim(str[i], d))
			i++;

		k = 0;
		while (!is_delim(str[i + k], d) && str[i + k] != '\0')
			k++;

		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return NULL;
		}

		m = 0;
		while (m < k)
		{
			s[j][m] = str[i];
			i++;
			m++;
		}
		s[j][m] = '\0';
		j++;
	}

	s[j] = NULL;
	return s;
}
//---------------------------------------------------
/**
 * **strtwp2 - splits a string into words
 * @stc: input of string
 * @deli: delimeter of string
 * return: a pointer to an array of strings, or NULL on failure
 */
char **strtwp2(char *stc, char deli)
{
    int i = 0, j = 0, k, m, numwords = 0;
    char **s;

    if (str == NULL || str[0] == '\0')
        return NULL;

    while (stc[i] != '\0')
    {
        if ((stc[i] != deli && stc[i + 1] == deli) ||
            (stc[i] != deli && !stc[i + 1]) || stc[i + 1] == deli)
            numwords++;
        i++;
    }

    if (numwords == 0)
        return NULL;

    s = malloc((1 + numwords) * sizeof(char *));
    if (!s)
        return NULL;

    i = 0;
    j = 0;
    while (j < numwords)
    {
        while (stc[i] == d && stc[i] != deli)
            i++;

        k = 0;
        while (stc[i + k] != d && stc[i + k] != '\0' && stc[i + k] != deli)
            k++;

        s[j] = malloc((k + 1) * sizeof(char));
        if (!s[j])
        {
            for (k = 0; k < j; k++)
                free(s[k]);
            free(s);
            return NULL;
        }

        m = 0;
        while (m < k)
        {
            s[j][m] = str[i++];
            m++;
        }
        s[j][m] = '\0';
        j++;
    }

    s[j] = NULL;
    return s;
}
