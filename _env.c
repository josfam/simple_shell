#include "shell.h"

/**
 * print_env - Prints the current environment.
 * @env: The current environment, as passed into main.
 * Description: Prints the current environment.
 * Return: Nothing
*/
void print_env(char **env)
{
	while (*env)
	{
		_puts(*env);
		_putchar('\n');
		env++;
	}
}
