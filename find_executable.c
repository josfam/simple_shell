#include <stddef.h>
#include <string.h>
#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
int _strcmpr(const char *str1, const char *str2, int n);
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
	char *tmp;

	if (_strchr(command, '/') != NULL)
		return (_strdup(command));
	while (token != NULL)
	{
		tmp_path = concatenate_strings(token, "/");
		if (tmp_path == NULL)
		{
			return (NULL);
		}
		if (path == NULL)
		{
			path = concatenate_strings(tmp_path, command);
			if (path == NULL)
			{
				free(tmp_path);
				return (NULL);
			}
		}
		else
		{
			tmp = concatenate_strings(path, command);
			if (tmp == NULL)
			{
				free(tmp_path);
				free(tmp);
				return (NULL);
			}
			free(path);
			path = tmp;
		}
		if (is_executable(path))
		{
			free(tmp_path);
			return (path);
		}
		free(tmp_path);
		free(path);
		path = NULL;
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
