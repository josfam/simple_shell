#include <stdlib.h>
#include "shell.h"

/**
 * _has_only_delims - Checks if the provided string is purely composed of only
 *                  delimiters.
 * @str: The string to check.
 * @delims: Delimiters to check for.
 * Description: Checks if the provided string is purely composed of only
 *              delimiters.
 * Return: 1 if the string is purely composed of only tokens, 0 otherwise.
 */
int _has_only_delims(char *str, char *delims)
{
	char *copy;
	char *copyPtr;

	copy = _strdup(str);
	copyPtr = copy;

	while (*copyPtr)
	{
		if (!(_is_delim(*copyPtr, delims)))
		{
			free(copy);
			return (0);
		}
		copyPtr++;
	}
	free(copy);
	return (1);
}

/**
 * _is_delim - Checks if the provided character is a delimiter.
 * @ch: The character to check.
 * @delims: The delimiter/delimiters string.
 * Description: Checks if the provided character is a delimiter.
 * Return: 1 if the provided character is a delimiter, 0 otherwise.
*/
int _is_delim(char ch, char *delims)
{
	int delim_len, i;

	delim_len = _strlen(delims);

	for (i = 0; i < delim_len; i++)
	{
		if (ch == delims[i])
			return (1);
	}

	return (0);
}
