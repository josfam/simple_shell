#include <stddef.h>
/**
 * _strchr - Locates the first occurence of a character in a string
 * @s: the string to search in
 * @c: the character to locate
 * Return: a pointer to the first occurence if the character is found
 *         Null if the character is not found
 */
char *_strchr(char *s, int c)
{
	while (*s != (char)c && *s != '\0')
		s++;
	return (*s == (char)c ? (char *)s : NULL);
}
