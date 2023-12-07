#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

char *get_prompt_input(void);

/**
 * main - Entry point.
 * Description: The main entry point of the program.
 * Return: 0 if successful, Non-zero otherwise.
 */
int main(void)
{
	char *argv[] = {NULL};
	char *user_input;
	pid_t fork_num;
	int status;

	while(1)
	{
		user_input = get_prompt_input();

		if (!user_input)
			return (-1);

		fork_num = fork();

		if (fork_num == 0) /* this is a child */
		{
			/* execute command entered by the user */
			if (execve(user_input, argv, __environ) == -1)
			{
				perror("Execution error");
				break;
			}
		}
		else
		{
			wait(&status); /* wait for the child to finish */
		}

	}
	printf("\n");

	return (0);
}

/**
 * get_prompt_input - Shows a terminal prompt, and gets terminal
 *                    inputs provided at said prompt.
 * Description: Shows a terminal prompt, and gets terminal
 *              inputs provided at said prompt.
 *              If no input is provided, the user is re-prompted.
 *              If CTRL+D is pressed, the program terminates.
 * Return: The input entered (if any), or NULL on error.
*/
char *get_prompt_input(void)
{
	ssize_t chars_read;
	char *input_buff;
	size_t buff_size;

	/* setup defaults for getline */
	chars_read = 0;
	input_buff = NULL;
	buff_size = 0;

	while (1)
	{
		/* show the prompt */
		printf("#cisfun$ ");
		chars_read = getline(&input_buff, &buff_size, stdin);

		/* error and EOF handling */
		if (chars_read == -1)
		{
			free(input_buff);
			return (NULL);
		}

		/* re-prompt if no input was provided */
		if (chars_read == 1)
			continue;
		else
			break;
	}

	/* replace the newline added by getline, for execve's sake */
	if (input_buff[chars_read - 1] == '\n')
		input_buff[chars_read - 1] = '\0';

	return (input_buff);
}
