#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
/**
 * _execvp - Executes a program/command, inside of a child process.
 * @command: The program/command to execute.
 * @args: Command line arguments for the program being executed.
 * Description:Executes the program without calling fork if the
 * command doesn't exist.
 * Return: 0 on success, -1 on error.
 */
int _execvp(char *command, char **args)
{
	pid_t fork_num;
	int wait_status;
	/* checks if the command can be executed */
	if (access(command, X_OK) != 0)
	{
		perror("Error");
		return (-1);
	}
	fork_num = fork();
	if (fork_num == -1)
	{
		perror("Error");
		return (-1);
	}
	if (fork_num == 0)
	{
		if (execve(command, args, NULL) == -1)
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
