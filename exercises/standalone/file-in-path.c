#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int has_key(char *environ_var, char *key);
char **get_key_value(char *environ_var);
char **get_tokens(char *to_split, char *delim);

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
	char *value; /* store the value of an environment variable */
	char **token_list;

	env = __environ;

	if (argc < 2)
	{
		printf("Usage: %s filename ...\n", argv[0]);
		return (-1);
	}

	/* Extract and print the PATH variable's value */
	while (*env != NULL)
	{
		env_item = *env;

		if (has_key(env_item, "PATH"))
			value = get_key_value(env_item)[1];
		env++;
	}
	token_list = get_tokens(value, ":");

	/* print every folder in the PATH value */
	while(*token_list!= NULL)
	{
		printf("%s\n", *token_list);
		token_list++;
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

/**
 * get_key_value - Returns the key and value of the given environment-
 *                 variable.
 * @environ_var: The environment variable whose key and value to extract
 *               and return.
 * Description: Returns the key and value of the given environment-
 *              variable.
 * Return: An array containing the key and value of the provided environment
 *         variable.
*/
char **get_key_value(char *environ_var)
{
	char **key_value;
	char *token, *delim;
	char *env_var; /* Writable copy of the environment variable */
	int i;

	env_var = strdup(environ_var);
	key_value = malloc(2 * sizeof(char *));
	delim = "=";
	i = 0;

	token = strtok(env_var, delim);

	while (token != NULL)
	{
		key_value[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}

	return (key_value);
}

/**
 * get_tokens - Return an array of tokens got by splitting the provided
 *              string by a given delimeter. 
 * @to_split: The string to split up.
 * @delim: The delimiter by which to split up the string.
 * Description: Return an array of tokens got by splitting the provided
 *              string by a given delimeter.
 * Return: An array of tokens got by splitting the provided string by
 *         a given delimeter.
*/
char **get_tokens(char *to_split, char *delim)
{
	int token_count, i;
	char *tally_str, *split_copy, *token;
	char **token_list;

	tally_str = strdup(to_split);
	token_count = 0;
	token = strtok(tally_str, delim);

	/* count how many tokens exist */
	while(token != NULL)
	{
		token_count++;
		token = strtok(NULL, delim);
	}

	/* store tokens in an array */
	split_copy = strdup(to_split);
	token_list = malloc(token_count * sizeof(char *));
	i = 0;
	token = strtok(split_copy, delim);

	while(token != NULL)
	{
		token_list[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}

	return (token_list);
}
