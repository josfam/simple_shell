#include <stdio.h>
#include <unistd.h>
#include "shell.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Entry point.
 * Description: The main entry point of the program.
 * Return: 0 if successful, Non-zero otherwise.
 */
int main(void)
{
	char *input;
	pid_t fork_num;
	int wait_status;
	char *argv[] = {NULL};

	while (1)
	{
		input = _get_prompt_input();
		if (!input) /* on error, or CTRL + D*/
			break;

		fork_num = fork();
		if (fork_num == -1)
		{
			perror("Error");
			break;
		}
		if (fork_num == 0) /* Child process */
		{
			if (execve(input, argv, __environ) == -1)
			{
				perror("Error");
			}
			_exit(0);
		}
		else
		{
			wait(&wait_status);
		}
	}

	_puts("\n");

	/* handle memory leaks */
	free(input);

	return (0);
}

