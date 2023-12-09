#include "exercise.h"
#include <unistd.h>

/**
 * _putchar - Writes a character to standard out.
 * @ch: The character to write to standard out.
 * Description: Writes a character to standard out.
 * Return: A non-negative number on success.
 */
int _putchar(char ch)
{
	write(1, &ch, sizeof(char));
	return (0);
}
