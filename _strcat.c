#include <stddef.h>
/**
 * _strcat - concatenates the string pointed to by src to the end
 * of the string
 *
 * @dest: pointer to the string dest
 * @src: pointer to the string src
 * Return: pointer to the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	if (dest == NULL || src == NULL)
		return (NULL);
	while (*dest)
		dest++;
	while ((*dest++ = *src++))
		;
	return (ptr);
}
