#include "shell.h"

/**
 * _puts - Prints a string to standard out.
 * @str: The string to print.
 * Description: Prints a string to standard out,
 *              and does not add a newline to the end.
 * Return: A non-negative number on success.
 */
int _puts(char *str)
{
	int i;
	int len = _strlen(str);

	for (i = 0; i < len; i++)
	{
		_putchar(str[i]);
	}

	return (0);
}
