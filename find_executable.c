#include <stddef.h>
#include <string.h>
#include "shell.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * is_executable - checks if the command can be executed
 * @path: the path of the command
 * Return: 0 or -1
 */
int is_executable(char *path)
{
	return (access(path, X_OK) == 0);
}

/**
 * get_path - gets the environment path
 * Return: pointed to the string containing the path
 */
char *get_path()
{
	char **env;

	for (env = __environ; *env; ++env)
	{
		/* Find the pair PATH=..., and return a pointer to the start of */
		/* the value after the = sign */
		if (_strcmpr(*env, "PATH=", 5) == 0)
			return (_strdup(*env + 5));
	}
	return (NULL);
}

/**
 * find_executable - finds the executable in path
 * @command: the command to be executed
 * @directories: the directories of path
 * Return: the command to execute
 */
char *find_executable(char *command, char *directories)
{
	char *token = strtok(directories, ":");
	char *path = NULL;
	char *tmp_path;

	if (_strchr(command, '/') != NULL) /* the command had a directory in it */
		return (_strdup(command));
	if (directories == NULL || directories[0] == '\0')
		return (NULL);
	while (token != NULL)
	{
		tmp_path = concat_strs(token, "/");

		if (tmp_path == NULL)
		{
			return (NULL);
		}
		path = concat_strs(tmp_path, command);
		if (path == NULL)
		{
			free(tmp_path);
			return (NULL);
		}
		/* return the full path to the executable if the path indeed points */
		/* to a an executable */
		if (is_executable(path))
		{
			free(tmp_path);
			return (path);
		}
		/* prepare to search the next directory in PATH for the executable */
		free_all(2, tmp_path, path);
		path = NULL;
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL); /* the executable was not found in the PATH */
}
