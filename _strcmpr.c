#include <stddef.h>
/**
 * _strcmpr - compares the first n characters of two strings
 * @str1: pointer to the the first string
 * @str2: pointer to the second string
 * @n: number of characters to compare
 * Return: 0 if equals, positive value if str1 is greater
 *         negative value otherwise
 */
int _strcmpr(char *str1, char *str2, int n)
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
