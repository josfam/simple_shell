#include <stdio.h>
#include "../shell.h"

/**
 * main - Entry point.
 * Description: The main entry point of the program.
 * Return: 0 if successful, Non-zero otherwise.
 */
int main(void)
{
	 
	char *tokens;
	char **separated;
	int test_count, i;

	test_count = 3;
	tokens = "/:*";
	char *test_strings[] = {
		"/Marie:Jordan:*/Andre",
		"/////",
		"*****ab/c/"
		};
	
	for(i = 0; i < test_count; i++)
	{
		separated = _get_tokens(test_strings[i], tokens);

		/* print the names */
		while(*separated)
		{
			printf("%s\n", *separated);
			separated++;
		}
		printf("----------------\n");
	}
	return (0);
}
