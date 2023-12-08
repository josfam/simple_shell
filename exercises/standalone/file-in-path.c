#include <stdio.h>
#include <unistd.h>
#include <string.h>

int has_key(char *environ_var, char *key);

/**
 * main - Entry point.
 * @argc: Length of array of commandline arguments.
 * @argv: Array of commandline arguments.
 * Description: The main entry point of the program.
 * Return: 0 if successful, Non-zero otherwise.
 */
int main(int argc, char *argv[])
{
	char **env; /* To store all environment variables */
	char *env_item; /* To store one environment variable */

	env = __environ;

	if (argc < 2)
	{
		printf("Usage: %s filename ...\n", argv[0]);
		return (-1);
	}

	/* Extract and print the PATH variable from the environment */
	while (*env != NULL)
	{
		env_item = *env;
		if (has_key(env_item, "PATH"))
			printf("%s\n", env_item);
		env++;
	}

	return (0);
}

/**
 * has_key - Returns whether or not the provided environment variable has the
 *           provided key.
 * @environ_var: The environment variable to check.
 * @key: The key to check for.
 * Description: Returns whether or not the provided environment variable has
 *              the provided key.
 * Return: 1 if the environment variable has the provided key, 0 if it does
 *         not.
 */
int has_key(char *environ_var, char *key)
{
	int key_len, env_var_len, i;

	key_len = strlen(key);
	env_var_len = strlen(environ_var);

	/* Eliminate non-matching environment variables */
	if (key_len >= env_var_len)
		return (0);

	for (i = 0; i < key_len; i++)
	{
		if (environ_var[i] != key[i])
			return (0);
	}

	/*eliminate environment variables that just happen to begin with the */
	/* characters in the key */
	if (environ_var[i] != '=')
		return (0);

	return (1);
}
