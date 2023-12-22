#include "shell.h"

/**
 * _is_env - Checks if the arguments represent a call to env.
 * @args: The arguments to check.
 * Description: Checks if the args is a call to env.
 * Return: 1 if the args was a call to exit, 0 if it was not.
*/
int _is_env(char **args)
{
	return ((_strcmp(args[0], "env") == 0) ? 1 : 0);
}

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
