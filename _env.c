#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

/**
 * print_env - Prints the current environment.
 * @env: The current environment, as passed into main.
 * Description: Prints the current environment.
 * Return: Nothing
*/
void print_env(char **env)
{
	while (*env)
	{
		_puts(*env);
		_putchar('\n');
		env++;
	}
}

/**
 * _setenv- Change or add an environment variable.
 * @key: The key to search for in the environment.
 * @value: The value to assign to the key, in the environment.
 * @env: The current environment variables.
 * @pool: The memory pool to store malloced memory.
 * Description: Checks if an environment variable with this key exists.
 * Return: 0 on success, -1 otherwise.
*/
int _setenv(char *key, char *value, char **env, memPool *pool)
{
	char *new_var;
	char **envPtr;
	int index = -1;

	envPtr = env;

	/* Replace the value of the key, if it already exists */
	if (key_exists(key, envPtr, &index))
	{
		new_var = concat_three(key, "=", value);
		if (!new_var)
			return -1;
		append_memory(pool, new_var);
		env[index] = new_var;
		return (0);
	}

	return (0);
}

/**
 * key_exists- Checks if an environment variable with this key exists.
 * @key: The key to search for in the environment.
 * @env: The current environment variables.
 * @index: Pointer that stores the location in the environment array
 *         where the key was found after a search was conducted.
 * Description: Checks if an environment variable with this key exists.
 * Return: 1 if the key exists, 0 otherwise.
*/
int key_exists(char *key, char **env, int *index)
{
	int env_len, i;
	char *key_equals;

	env_len = len_arr(env);
	key_equals = concat_three(key, "=", "");

	for (i = 0; i < env_len; i++)
	{
		if (starts_with(env[i], key_equals))
		{
			/* Record the location of this key */
			*index = i;
			free(key_equals);
			return (1);
		}
	}
	free(key_equals);
	return (0);
}
