#include "shell.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * concat_strs - concatenated two strings without memory leaks
 * @str1: first string of characters
 * @str2: second string of characters
 * Return: the two string concatenated
 */
char *concat_strs(char *str1, char *str2)
{
	char *result = malloc(_strlen(str1) + _strlen(str2) + 1);

	_strcpy(result, str1);
	_strcat(result, str2);
	return (result);
}
