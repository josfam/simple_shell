#include <stddef.h>
#include <stdio.h>
#include "shell.h"

/**
 * starts_with - Checks if string, s1 starts with another string, s2.
 * @s1: The string to check
 * @s2: The other string to use for checking.
 * Description: Checks if string, s1 starts with another string, s2.
 * Return: 1 if s1 starts with s2, 0 otherwise.
 */
int starts_with(char *s1, char *s2)
{
	int s1_len, s2_len, least_len, i;

	s1_len = _strlen(s1);
	s2_len = _strlen(s2);

	/* s1 cannot start with s2, if s2 is longer */
	if (s2_len > s1_len)
		return (0);

	least_len = (s1_len > s2_len) ? s2_len : s1_len;

	for (i = 0; i < least_len; i++)
	{
		if (s1[i] != s2[i])
			return (0);
	}

	return (1);
}
