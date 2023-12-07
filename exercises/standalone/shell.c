#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * main - Entry point.
 * Description: The main entry point of the program.
 * Return: 0 if successful, Non-zero otherwise.
 */
int main(void)
{
	ssize_t chars_read;
	char *input_buff;
	size_t buff_size;
	char *command;
	char *argv[] = {NULL};

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
			break;
		}

		/* accept no input */
		if (chars_read == 1)
			continue;

		/* replace the newline added by getline, for execve's sake */
		if (input_buff[chars_read - 1] == '\n')
			input_buff[chars_read - 1] = '\0';

		command = input_buff;

		/* execute the command */
		if (execve(command, argv, __environ) == -1)
		{
			perror("Execution error");
		}
	}

	printf("\n");

	return (0);
}
