#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * _exec_in_child - Executes a program/command, inside of a child process.
 * @args: Command line arguments for the program being executed.
 * @argv: Argument vector first used when invoking the shell.
 * @env: Environment variables from the current environment.
 * Description: Executes a program/command, inside of a child process.
 * Return: 0 on success, -1 on error.
*/
int _exec_in_child(char **args, char **argv, char **env)
{
	pid_t fork_num;
	int wait_status;
	char *command;

	command = args[0];

	fork_num = fork();
	if (fork_num == -1)
	{
		perror("Error");
		return (-1);
	}

	if (fork_num == 0) /* Child process */
	{
		if (execve(command, args, env) == -1)
		{
			perror(argv[0]);
		}
		_exit(0);
	}
	else
	{
		wait(&wait_status);
	}

	return (0);
}
