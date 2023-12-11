#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

int _execute(char *command, char **argv, char **env);

/**
 * main - Entry point.
 * Description: The main entry point of the program.
 * Return: 0 if successful, Non-zero otherwise.
 */
int main(void)
{
	char *input;
	char **args;

	while (1)
	{
		input = _get_prompt_input();
		/* on input error, CTRL + D*/
		if (!input)
			break;

		args = _get_tokens(input, " ");
		if (_execute(args[0], args, __environ) == -1)
			break;
	}

	_puts("\n");

	/* handle memory leaks */
	free(input);

	return (0);
}
