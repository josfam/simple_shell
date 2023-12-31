#include <stddef.h>
#include <stdlib.h>
#include "shell.h"

/**
 * _strcpy - copies the string pointed to by src to the string
 * pointed to by dest
 * @dest: pointer to the string dest
 * @src: pointer to the string src
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	char *ptr = dest;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}
	while ((*dest++ = *src++))
		;
	return (ptr);
}

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

/**
 * _strncpy - copy n characters from src to dest
 * @dest: destination string
 * @src: source string
 * @n: number of characters to copy
 * Return: pointer to destination string
 */
char *_strncpy(char *dest, const char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; ++i)
		dest[i] = src[i];
	while (i < n)
	{
		dest[i] = '\0';
		++i;
	}
	return (dest);
}
