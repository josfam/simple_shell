#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

int _is_delim(char ch, char *delims);

/**
 * _get_tokens - Returns an array of tokens got by splitting up the
 *               provided string using the given delimiter/delimiters.
 * @str: The string to split into tokens.
 * @delims: The delimiter/delimiters with which to split the string into
 *          tokens.
 * Return: An array of tokens got by splitting up the provided string using
 *         the given delimeter/delimiters.
 *         An array with one pointer to the original string is returned,
 *         if the string does not contain any delimiter.
 *         NULL is returned if either str or delims is NULL.
*/
char **_get_tokens(char *str, char *delims)
{
	char *copy, *copyPtr, *token;
	int delim_count, i;
	char **tokens;

	if (!str || !delims)
		return (NULL);

	delim_count = 0;
	copy = _strdup(str);
	copyPtr = copy;

	while (*copyPtr)
	{
		if (_is_delim(*copyPtr, delims))
			delim_count++;
		copyPtr++;
	}
	copyPtr = copy; /* reset pointer */

	/* Return an array which points to the provided string */
	if (delim_count == 0)
	{
		tokens = malloc(1 * sizeof(char *));
		tokens[0] = copy;
		return (tokens);
	}

	/* Allocate as much space as delimiters with one extra space */
	tokens = malloc((delim_count + 1) * sizeof(char *));

	i = 0;
	token = strtok(copy, delims);

	while (token != NULL)
	{
		tokens[i] = _strdup(token);
		token = strtok(NULL, delims);
		i++;
	}

	return (tokens);
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

/**
 * count_tokens - Counts the number of tokens, separated by
 *                the given delimiters, in the given string.
 * @str: The string in which to count tokens.
 * @delims: The delimiters to use when finding tokens.
 * Description:  Counts the number of tokens, separated by
 *               the given delimiters, in the given string.
 * Return: The number of tokens found in the given string.
 */
int count_tokens(char *str, char *delims)
{
	char *tallying, *token;
	int token_count;

	tallying = _strdup(str);
	token_count = 0;

	token = strtok(tallying, delims);
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, delims);
	}

	return (token_count);
}
