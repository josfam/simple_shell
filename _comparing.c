#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
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

/**
 * _strcmp - Compares two strings for equality.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * Description: Compares two strings for equality.
 * Return: 0 if the strings are equal,
 *         1 if s1 is greater than s2,
 *         -1 if s1 is less than s2.
*/
int _strcmp(char *s1, char *s2)
{
	int s1_len, s2_len, min_loops, i;

	s1_len = _strlen(s1);
	s2_len = _strlen(s2);

	/* handle quick cases */
	if (s1_len > 0 && s2_len == 0) /* s1 > s2 */
		return (1);
	if (s1_len == 0 && s2_len > 0) /* s1 < s2 */
		return (-1);
	if (s1_len == 0 && s2_len == 0) /* s1 == s2 */
		return (0);

	/* Use the shortest string to iterate */
	min_loops = (s1_len > s2_len) ? s2_len : s1_len;

	for (i = 0; i < min_loops; i++)
	{
		if (s1[i] > s2[i]) /* s1 > s2*/
			return (1);
		if (s1[i] < s2[i]) /* s1 < s2 */
			return (-1);
	}

	/* handle one string being a sub-string */
	if (s1_len > s2_len)
		return (1);
	if (s1_len < s2_len)
		return (-1);

	return (0);
}

/**
 * _strcmpr - compares the first n characters of two strings
 * @str1: pointer to the the first string
 * @str2: pointer to the second string
 * @n: number of characters to compare
 * Return: 0 if equals, positive value if str1 is greater
 *         negative value otherwise
 */
int _strcmpr(char const *str1, const char *str2, int n)
{
	while (n > 0 && *str1 && *str2 && *str1 == *str2)
	{
		++str1;
		++str2;
		--n;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
 * is_same - Checks if string s1 is the same as the command, s2.
 * @s1: The string to check.
 * @s2: The command to be used for checking.
 * Description: Checks if string s1 is the same as the command, s2.
 * Return: 1 if s1 is the same as s2, 0 otherwise.
*/
int is_same(char *s1, char *s2)
{
	return (_strcmp(s1, s2) == 0);
}
