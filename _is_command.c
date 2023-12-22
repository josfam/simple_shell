#include <stdlib.h>
#include "shell.h"

/**
 * is_command - Checks if string s1 is the same as the command, s2.
 * @s1: The string to check.
 * @s2: The command to be used for checking.
 * Description: Checks if string s1 is the same as the command, s2.
 * Return: 1 if s1 is the same as s2, 0 otherwise.
*/
int is_command(char *s1, char *s2)
{
	return (_strcmp(s1, s2) == 0);
}
