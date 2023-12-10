#include <stdio.h>
#include <unistd.h>
#include "shell.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int _execute(char *command, char **argv, char **env);

/**
 * main - Entry point.
 * Description: The main entry point of the program.
 * Return: 0 if successful, Non-zero otherwise.
 */
int main(void)
{
	char *input;
	char *args[] = {NULL};

	while (1)
	{
		input = _get_prompt_input();
		if (!input) /* on error, or CTRL + D*/
			break;
		if (_execute(input, args, __environ) == -1)
			break;
	}

	_puts("\n");

	/* handle memory leaks */
	free(input);

	return (0);
}

/**
 * _execute - Executes a program/command, inside of a child process.
 * @command: The program/command to execute.
 * @args: Command line arguments for the program being executed.
 * @env: Environment variables to be passed to the program.
 * Description: Executes a program/command, inside of a child process.
 * Return: 0 on success, -1 on error.
*/
int _execute(char *command, char **args, char **env)
{
	pid_t fork_num;
	int wait_status;

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
			perror("Error");
		}
		_exit(0);
	}
	else
	{
		wait(&wait_status);
	}

	return (0);
}
