#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include <sys/types.h>
#include <stdio.h>

/**
 * main - Entry point.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 * @env: Environment variables from the current environment.
 * Description: The main entry point of the program.
 * Return: 0 if successful, Non-zero otherwise.
 */
int main(__attribute__((unused)) int argc, char **argv, char **env)
{
	char **args;
	char *input, *command, *directories, *executable_path, *env_path;
	int is_interactive;
	const int MAX_DIRECTORIES_LEN = 1024;

	is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		input = _get_prompt_input(is_interactive);
		/* on input error, CTRL + D*/
		if (!input)
			break;

		args = _get_tokens(input, " ");

		if (_is_exit_call(args))
		{
			/* exit immediately */
			free(args);
			__exit();
		}
		directories = malloc(MAX_DIRECTORIES_LEN);

		if (directories == NULL)
		{
			perror("Error allocating memory");
			return (EXIT_FAILURE);
		}

		env_path = get_path();
		if (env_path == NULL)
		{
			perror("Error getting current directory");
			_free_all(2, input, directories);
			return (EXIT_FAILURE);
		}

		_strncpy(directories, env_path, MAX_DIRECTORIES_LEN - 1);
		directories[MAX_DIRECTORIES_LEN - 1] = '\0';
		free(env_path);
		command = args[0];
		executable_path = find_executable(command, directories);

		if (executable_path == NULL)
		{
			perror("Error finding executable");
			return (EXIT_FAILURE);
		}

		if (_execvp(executable_path, args, argv, env) == -1)
			break;
	}

	if (is_interactive)
		_puts("\n");

	/* handle memory leaks */
	_free_all(3, args, input, directories);

	return (0);
}
