#include "shell.h"
#include <stdlib.h>

/**
 * _strdup - Return a duplicate of the provided string.
 * @str: The original string to duplicate.
 * Description: Return a duplicate of the provided string.
 * Return: A duplicate of the provided string, and NULL if the original
 *         string is NULL.
 */
char *_strdup(char *str)
{
	int str_len, i;
	char *duplicate;

	if (!str)
		return (NULL);

	/* allocate as much memory as the original string */
	str_len = _strlen(str);
	duplicate = (char *)malloc((str_len + 1) * sizeof(char));
	if (!duplicate)
		return (NULL);

	/* copy over the characters */
	for (i = 0; i < str_len; i++)
	{
		duplicate[i] = str[i];
	}

	/* add null terminator */
	duplicate[i] = '\0';

	return (duplicate);
}
