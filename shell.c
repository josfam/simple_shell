#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include <sys/types.h>
#include <stdio.h>

char *get_dir_mem(int max_space, char *program, char *input, char **args);
char *get_path_dirs(char *program, char *input, char *dir_mem, char **args);

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
	char *input, *command, *dir_mem, *executable_path, *env_path;
	int is_interactive;
	const int MAX_DIR_LEN = 1024;

	is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		input = get_prompt_input(is_interactive);
		/* on input error, CTRL + D*/
		if (!input)
			break;

		args = get_tokens(input, DELIMS);
		command = args[0];

		if (is_same(command, "exit")) /* exit immediately */
		{
			free(input);
			__exit();
		}
		if (is_same(command, "env")) /* print the environment*/
		{
			print_env(env);
			free(input);
			continue;
		}

		dir_mem = get_dir_mem(MAX_DIR_LEN, argv[0], input, args);
		env_path = get_path_dirs(argv[0], input, dir_mem, args);
		free(input);

		_strncpy(dir_mem, env_path, MAX_DIR_LEN - 1);
		dir_mem[MAX_DIR_LEN - 1] = '\0';
		free(env_path);
		executable_path = find_executable(command, dir_mem);

		if (executable_path == NULL)
		{
			free_tokens(args);
			free_all(2, executable_path, dir_mem);
			perror("Error finding executable");
		}

		if (_execvp(executable_path, args, argv, env) == -1)
		{
			free_tokens(args);
			free_all(2, executable_path, dir_mem);
			break;
		}
		free_tokens(args);
		free_all(2, executable_path, dir_mem);
	}

	if (is_interactive)
		_puts("\n");

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
char *get_dir_mem(int max_space, char *program, char *input, char **args)
{
	void *dir_memory;

	dir_memory = malloc(max_space);

	if (dir_memory == NULL)
	{
		perror(program);
		free_all(2, input, args);
		exit(EXIT_FAILURE);
	}

	return ((char *)dir_memory);
}

/**
 * get_path_dirs - Finds and returns the directories in the PATH variable.
 * @program: The first argument of main's argv.
 * @input: Un-tokenized commands passed into the custom shell's prompt.
 * @dir_mem: Memory that will contain directories from the PATH variable.
 * @args: Tokenized commands passed into the custom shell's prompt.
 * Description: Finds and returns the directories in the PATH variable.
 * Return: Directories in the PATH variable.
 *         Exits if no such directories exited.
*/
char *get_path_dirs(char *program, char *input, char *dir_mem, char **args)
{
	char *path_dirs;

	path_dirs = get_path();
	if (path_dirs == NULL)
	{
		perror(program);
		free_all(4, input, dir_mem, args, path_dirs);
		exit(EXIT_FAILURE);
	}

	return (path_dirs);
}
