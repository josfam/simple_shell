#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork example
 * 
 * Return: Always 0.
*/
int main(void)
{
	pid_t fork_num;
	int status;
	
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	fork_num = fork();

	if (fork_num == -1)
	{
		perror("Error:");
		return (1);
	}

	if (fork_num == 0) /* This is a child process */
	{
		if (execve(argv[0], argv, __environ) == -1)
		{
			perror("Error:");
		}
		_exit(0); /* For proper termination of child process after a fail */
	}
	else
	{
		wait(&status);
	}

	return (0);
}
