#include "shell.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>

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

/**
 * _concat_all - Concatenates all given strings together.
 * @how_many: How many strings to concatenate.
 * Description: Concatenates all given strings together.
 * Return: A pointer to the combined string.
 */
char *_concat_all(int how_many, ...)
{
	int i, j, final_size;
	char *str, *fused, *fusedPtr;

	va_list args;

	va_start(args, how_many);
	for (i = 0; i < how_many; i++) /* Count necessary memory size */
	{
		str = va_arg(args, char *);
		final_size += _strlen(str);
	}
	final_size++; /* Add null terminator */
	va_end(args);

	fused = (char *)malloc(final_size * sizeof(char *));
	if (!fused)
		return (NULL);

	fusedPtr = fused;

	va_start(args, how_many);
	for (i = 0; i < how_many; i++) /* copy over values */
	{
		str = va_arg(args, char *);
		for (j = 0; j < _strlen(str); j++)
		{
			*fusedPtr = str[j];
			fusedPtr++;
		}
	}
	va_end(args);

	return (fused);
}
