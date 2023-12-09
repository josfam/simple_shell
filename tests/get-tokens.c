#include <stdio.h>
#include "../shell.h"

/**
 * main - Entry point.
 * Description: The main entry point of the program.
 * Return: 0 if successful, Non-zero otherwise.
 */
int main(void)
{
	char *names, *tokens;
	char **separate_names;

	names = "/Marie:Jordan:*/Andre";
	tokens = "/:*";
	separate_names = _get_tokens(names, tokens);

	/* print the names */
	while(*separate_names)
	{
		printf("%s\n", *separate_names);
		separate_names++;
	}

	return (0);
}
