#include "exercise.h"

/**
 * _strlen - Returns the length of a null-terminated string.
 * @s: The string whose length to return.
 * Description: Returns the length of a null-terminated string.
 * Return: The length of the string, s.
 */
int _strlen(char *s)
{
	int len;
	int counter;

	counter = 0;
	len = 0;

	while (*(s + counter) != '\0')
	{
		len++;
		counter++;
	}

	return (len);
}

