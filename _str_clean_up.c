#include <stddef.h>
#include <stdio.h>
#include "shell.h"

/**
 * _strip - Strip whitespace from both ends of a string.
 */
char * _strip(char *str)
{
	char *startPtr, *endPtr;
	int str_len;

	if (!str)
		return (NULL);

	str_len = _strlen(str);
	if (str_len == 0)
		return "";

	startPtr = str;
	endPtr = str + (str_len - 1); /* placed right before the \0 */

	while(*startPtr == ' ' && startPtr != endPtr)
		startPtr++;

	if (startPtr == endPtr) /* string was all white space */
		return "";

	// #if 0

	// #endif
	return startPtr;
}
