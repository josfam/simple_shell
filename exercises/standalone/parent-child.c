#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - fork example
 * 
 * Return: Always 0.
*/
int main(void)
{
	pid_t my_pid;
	pid_t fork_num;

	fork_num = fork();

	if (fork_num == -1)
	{
		perror("Error:");
		return (1);
	}

	my_pid = getpid(); /* Both processes will request their pids */

	printf("My pid is: %u\n", my_pid);

	if (fork_num == 0) /* The current process is a child */
	{
		printf("I, (%u), am the child.\n", my_pid);
	}
	else
	{
		printf("I, (%u), am the parent.\n", my_pid);
	}

	return 0;
}
