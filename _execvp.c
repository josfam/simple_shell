#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
/**
 * _execvp - Executes a program/command, inside of a child process.
 * @command: The program/command to execute.
 * @args: Command line arguments for the program being executed.
 * @argv: The argument vector first passed main when the shell was invoked.
 * @env: The environment variables passed to this process.
 * Description:Executes the program without calling fork if the
 * command doesn't exist.
 * Return: 0 on success, -1 on error.
 */
int _execvp(char *command, char **args, char **argv, char **env)
{
	pid_t fork_num;
	int wait_status;
	char *program = argv[0];

	/* checks if the command can be executed */
	if (access(command, X_OK) != 0)
	{
		perror(program);
		return (-2);
	}
	fork_num = fork();
	if (fork_num == -1)
	{
		perror(program);
		return (-1);
	}
	if (fork_num == 0)
	{
		if (execve(command, args, env) == -1)
		{
			perror(program);
		}
		_exit(0);
	}
	else
	{
		wait(&wait_status);
	}
	return (0);
}
