#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr", NULL};

	#if 0
	/* with echo */
	char *argv[] = {"/bin/echo", "$HOME", NULL};

	/* with cat */
	char *argv[] = {"/bin/cat", "/proc/sys/kernel/pid_max", NULL};
	#endif

	printf("Before execve\n");
	if (execve(argv[0], argv, __environ) == -1)
	{
		perror("Error:");
	}
	printf("After execve\n");
	return (0);
}
