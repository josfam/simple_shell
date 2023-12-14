#include <stddef.h>
#include <stdio.h>
#include "shell.h"

/**
 * _strip - Strip whitespace from both ends of a string.
 * @str: The string whose whitespace to strip.
 * Description: Strip whitespace from both ends of a string.
 * Return: The string without whitespace.
 */
char *_strip(char *str)
{
	char *startPtr, *endPtr, *copy;
	int str_len;

	if (!str)
		return (NULL);

	copy = _strdup(str);
	str_len = _strlen(copy);

	if (str_len == 0)
		return ("");

	startPtr = copy;
	endPtr = copy + str_len; /* placed at the \0 */

	while ((startPtr < endPtr) && (*startPtr == ' '))
		startPtr++;

	if (startPtr == endPtr) /* string was all white space */
		return ("");

	while ((startPtr < endPtr) && (*(endPtr - 1) == ' '))
	{
		endPtr--;
	}

	*endPtr = '\0';
	return (startPtr);
}
