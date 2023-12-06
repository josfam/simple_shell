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
	const int MAX_PROCESSES = 5;
	pid_t fork_num;
	int status;
	int i;

	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0; i < MAX_PROCESSES; i++)
	{
		fork_num = fork();

		if (fork_num == -1)
		{
			perror("Error:");
			return (1);
		}

		if (fork_num == 0) /* This is a child process */
		{
			sleep(2);
			if (execve(argv[0], argv, __environ) == -1)
			{
				perror("Error:");
			}
			_exit(0); /* For proper termination of child process after a fail */
		}
		else
		{
			/* waiting for this process to finish */
			wait(&status);
		}
	}

	return (0);
}
