#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

int _is_delim(char ch, char *delims);
int count_tokens(char *str, char *delims);
int _has_only_delims(char *str, char *delims);

/**
 * _get_tokens - Returns a NULL-terminated array of tokens got by splitting up
 *               the provided string using the given delimiter/delimiters.
 * @str: The string to split into tokens.
 * @delims: The delimiter/delimiters with which to split the string into
 *          tokens.
 * Return: A NULL-terminated array of tokens got by splitting up the provided
 *         string using the given delimeter/delimiters.
 *         An array with one pointer to the original string is returned,
 *         if the string does not contain any delimiter.
 *         NULL is returned if either str or delims is NULL.
*/
char **_get_tokens(char *str, char *delims)
{
	char *tallying, *tokenizing, *token;
	int token_count, i;
	char **tokens;

	if (!str || !delims)
		return (NULL);

	tallying = _strdup(str);
	token_count = count_tokens(tallying, delims);

	/* Return a NULL-terminated array which points to the provided string */
	if (token_count == 0 && !_has_only_delims(tallying, delims))
	{
		free(tallying);
		tokens = malloc(2 * sizeof(char *));
		tokens[0] = tallying;
		tokens[1] = NULL;
		return (tokens);
	}

	/* Allocate space for tokens and a NULL termination */
	tokens = malloc((token_count + 1) * sizeof(char *));

	/* Add each found token to the array of tokens */
	i = 0;
	tokenizing = _strdup(str);
	token = strtok(tokenizing, delims);

	while (token != NULL)
	{
		tokens[i] = _strdup(token);
		token = strtok(NULL, delims);
		i++;
	}
	tokens[i] = NULL;
	_free_all(2, tallying, tokenizing);
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
	free (tallying);
	return (token_count);
}

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
	while (*str)
	{
		if (!(_is_delim(*str, delims)))
			return (0);
		str++;
	}
	return (1);
}
