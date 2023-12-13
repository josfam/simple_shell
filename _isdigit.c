#include "shell.h"

/**
 * _isdigit - Checks if a character is a digit.
 * @c: The character to be checked.
 * Description: Checks for a digit (0 through 9).
 * Return: 1 if c is a digit, 0 otherwise.
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
