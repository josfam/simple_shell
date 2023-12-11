#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * _exec_in_child - Executes a program/command, inside of a child process.
 * @command: The program/command to execute.
 * @args: Command line arguments for the program being executed.
 * Description: Executes a program/command, inside of a child process.
 * Return: 0 on success, -1 on error.
*/
int _exec_in_child(char *command, char **args)
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
		if (execvp(command, args) == -1)
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
