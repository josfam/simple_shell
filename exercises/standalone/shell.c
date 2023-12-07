#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

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
	}
	printf("\n");

	return (0);
}
