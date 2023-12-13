#include <stddef.h>
/**
 * _strcpy - copies the string pointed to by src to the string
 * pointed to by dest
 * @dest: pointer to the string dest
 * @src: pointer to the string src
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}
	while ((*dest++ = *src++))
		;
	return (ptr);
}
