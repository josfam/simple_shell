#include <stdio.h>
#include <unistd.h>

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

	/* print the elements in the environment */
	while (*env != NULL)
	{
		env_item = *env;
		printf("%s\n", env_item);
		env++;
	}
	
	return (0);
}
