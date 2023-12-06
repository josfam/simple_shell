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
	pid_t pid;

	printf("Before fork\n");
	pid = fork(); /* separate processes created here */

	if (pid == -1)
	{
		perror("There was an error forking the process.");
		return (-1);
	}

	printf("After fork\n");
	my_pid = getpid();
	printf("My pid is %u\n", my_pid);

	return (0);
}

/**
 * Things Learned:
 * 
 * The assignment pid = fork() is for error checking later
 * (checking if fork returned -1)
 * fork() by itself would still have produced similar results 
*/
