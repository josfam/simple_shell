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
	int status; /* storing int returned by wait */

	fork_num = fork();

	if (fork_num == -1)
	{
		perror("Error:");
		return (1);
	}
	if (fork_num == 0) /* this process is a child */
	{
		printf("I am the executing child. Parent is waiting!\n");
		sleep(3);
	}
	else
	{
		wait(&status);
		printf("I am the parent. I am done waiting.\n");
	}

	return (0);
}
