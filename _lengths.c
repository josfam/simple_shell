#include "shell.h"

/**
 * _argc - Returns the argument count for the program/command entered.
 * @argv: The array of commands and arguments whose length to get.
 * Description: Returns the argument count for the program/command entered.
 *              The program name itself counts towards the length.
 *              If the argv array is explicitly NULL-terminated, that NULL
 *              does not count towards the length.
 *              The array {"/bin/ls", "/tmp", NULL} would have length 2,
 *              and so would the array {"/bin/ls", "/tmp"}.
 * Return: The argument count for the program/command entered.
 */
int _argc(char **argv)
{
	int len;

	len = 0;

	while (*argv)
	{
		len++;
		argv++;
	}

	return (len);
}
