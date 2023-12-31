#include "shell.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * concat_strs - concatenated two strings without memory leaks
 * @str1: first string of characters
 * @str2: second string of characters
 * Return: the two string concatenated
 */
char *concat_strs(char *str1, char *str2)
{
	char *result = malloc(_strlen(str1) + _strlen(str2) + 1);

	_strcpy(result, str1);
	_strcat(result, str2);
	return (result);
}

/**
 * concat_three - Concatenates three strings together.
 * @s1: The first string that will appear in the left-most position.
 * @s2: The second string that will appear in the middle position.
 * @s3: The third string that will appear in the right-most position.
 * Description: Concatenates three strings together.
 * Return: A string that is the result of concatenating three strings.
*/
char *concat_three(char *s1, char *s2, char *s3)
{
	char *fused;
	int final_size, s1_len, s2_len, s3_len, i, j;

	if (!s1 || !s2 || !s3)
		return (NULL);

	s1_len = _strlen(s1);
	s2_len = _strlen(s2);
	s3_len = _strlen(s3);

	final_size = s1_len + s2_len + s3_len + 1;
	fused = (char *)malloc(final_size * sizeof(char));
	i = 0;
	j = 0;

	/* copy over s1, s2, and s3 values */
	for (i = 0; i < s1_len; i++, j++)
	{
		fused[j] = s1[i];
	}

	for (i = 0; i < s2_len; i++, j++)
	{
		fused[j] = s2[i];
	}

	for (i = 0; i < s3_len; i++, j++)
	{
		fused[j] = s3[i];
	}
	fused[j] = '\0';

	return (fused);
}
