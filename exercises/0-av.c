#include "exercise.h"
#include <stdio.h>

/**
 * main - Prints all the arguments without using ac.
 * @ac: The number of arguments passed.
 * @av: NULL terminated array of strings.
 * Description: Prints command-line arguments.
 * Returns: 0 on success.
 */
int main(__attribute__((unused)) int ac, char **av)
{
	char **strPtr;
	char *thisChar;

	strPtr = av;

	while (*strPtr != NULL) /* keep going while there is a pointer there. */
	{
		thisChar = *strPtr;

		while(*thisChar != '\0')
		{
			_putchar(*thisChar);
			thisChar++;
		}
		_putchar(' ');

		strPtr++;
	}
	_putchar('\n');

	return (0);
}
