#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include <sys/types.h>
#include <stdio.h>
int _execvp(char *command, char **arg);
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
	char *input;
	char **args;
	char *command;
	char *directories;
	char *executable_path;
	char *env_path;
	const int MAX_DIRECTORIES_LEN = 1024;

	while (1)
	{
		input = _get_prompt_input();
		/* on input error, CTRL + D*/
		if (!input)
			break;

		args = _get_tokens(input, " ");
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
			free(input);
			free(directories);
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

		if (_execvp(executable_path, args) == -1)

		if (_is_exit_call(args))
			__exit();

		if (_exec_in_child(args, argv, env) == -1)
			break;
	}

	_puts("\n");

	/* handle memory leaks */
	free(input);
	free(directories);

	return (0);
}
