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
 * _is_exit_call - Checks if the args is a call to the exit args.
 * @args: The args to check.
 * Description: Checks if the args is a call to the exit args.
 * Return: 1 if the args was a call to exit, 0 if it was not.
*/
int _is_exit_call(char **args)
{
	if (_strcmp(args[0], "exit") != 0)
	{
		return (0);
	}
	if (_len_arr(args) == 1) /* exit was called alone */
	{
	return (1);
	}
	return (0);
}
