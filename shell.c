#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**
 * main - Entry point.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 * Description: The main entry point of the program.
 * Return: 0 if successful, Non-zero otherwise.
 */
int main(__attribute__((unused)) int argc, char **argv)
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
		if (_is_exit_call(args))
			__exit();
		if (_exec_in_child(args, argv) == -1)
			break;
	}

	_puts("\n");

	/* handle memory leaks */
	free(input);

	return (0);
}
