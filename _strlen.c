#include "shell.h"

/**
 * _strlen - Returns the length of a null-terminated string.
 * @str: The string whose length to return.
 * Description: Returns the length of a null-terminated string.
 * Return: The length of the string, s.
 */
int _strlen(char *str)
{
	int len;
	int counter;

	counter = 0;
	len = 0;

	while (*(str + counter) != '\0')
	{
		len++;
		counter++;
	}

	return (len);
}
