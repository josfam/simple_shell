#include <unistd.h>
#include "shell.h"

/**
 * __exit - Exits the shell program.
 */
void __exit(void)
{
	_exit(0);
}

/**
 * _is_exit_call - Checks if the command is a call to the exit command.
 * @command: The command to check.
 * Description: Checks if the command is a call to the exit command.
 * Return: 1 if the command was a call to exit, 0 if it was not.
*/
int _is_exit_call(char *command)
{
	if (_strcmp(command, "exit") != 0)
		return (0);

	return (1);
}
