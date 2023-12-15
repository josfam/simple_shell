#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include <sys/types.h>
#include <stdio.h>

void *get_dir_mem(int max_space, char *program, char *input, char **args);

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
	char *input, *command, *dirs, *executable_path, *env_path;
	int is_interactive;
	const int MAX_DIR_LEN = 1024;

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

		dirs = get_dir_mem(MAX_DIR_LEN, argv[0], input, args);

		env_path = get_path();
		if (env_path == NULL)
		{
			perror("Error getting current directory");
			_free_all(2, input, dirs);
			return (EXIT_FAILURE);
		}

		_strncpy(dirs, env_path, MAX_DIR_LEN - 1);
		dirs[MAX_DIR_LEN - 1] = '\0';
		free(env_path);
		command = args[0];
		executable_path = find_executable(command, dirs);

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
	_free_all(3, args, input, dirs);

	return (0);
}

/**
 * get_dir_mem - Allocates and returns memory space for directories in PATH.
 * @max_space: How much memory to allocate.
 * @program: The first argument of main's argv.
 * @input: Un-tokenized commands passed into the custom shell's prompt.
 * @args: Tokenized commands passed into the custom shell's prompt.
 * Description: Allocates and returns memory space for directories in PATH.
 * Return: Memory space.
 */
void *get_dir_mem(int max_space, char *program, char *input, char **args)
{
	void *dir_memory;

	dir_memory = malloc(max_space);

	if (dir_memory == NULL)
	{
		perror(program);
		_free_all(2, input, args);
		exit(EXIT_FAILURE);
	}

	return (dir_memory);
}
