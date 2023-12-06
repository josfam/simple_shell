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
	pid_t some_pid;

	some_pid = fork();

	if (some_pid == -1)
	{
		perror("Error:");
		return (1);
	}

	my_pid = getpid(); /* Both processes will request their pids */

	printf("My pid is: %u\n", my_pid);

	if (some_pid == 0) /* This was the child */
	{
		printf("I, (%u), am the child.\n", my_pid);
	}
	else
	{
		printf("I, (%u), am the parent of (%u)\n", my_pid, some_pid);
	}

	return 0;
}

/**
 * Still a little confused about the chronology of events here.
*/