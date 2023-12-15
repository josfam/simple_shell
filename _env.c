#include "shell.h"

/**
 * _is_env_call - Checks if the command is a call to the exit command.
 * @command: The command to check.
 * Description: Checks if the command is a call to the exit command.
 * Return: 1 if the command was a call to exit, 0 if it was not.
*/
int _is_env_call(char *command)
{
	return ((_strcmp(command, "env") == 0) ? 1 : 0);
}

/**
 * _print_env - Prints the current environment.
 * @env: The current environment, as passed into main.
 * Description: Prints the current environment.
 * Return: Nothing
*/
void _print_env(char **env)
{
	while (*env)
	{
		_puts(*env);
		_putchar('\n');
		env++;
	}
}
