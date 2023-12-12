#include <stddef.h>
#include "shell.h"

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
	if (s1_len > s2_len)
		min_loops = s2_len;
	else if (s1_len < s2_len)
		min_loops = s1_len;
	else
		min_loops = s1_len;

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
