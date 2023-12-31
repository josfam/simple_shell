#include <stdlib.h>
#include <stdio.h>
#include "../shell.h"

/**
 * main - Entry point.
 * Description: The main entry point of the program.
 * Return: 0 if successful, Non-zero otherwise.
 */
int main(void)
{
	char *first, *middle, *last, *full;
	char *empty;

	first = "Jordan";
	middle = " Moreau";
	last = " Li";
	empty = "";

	full = concat_three(first, middle, last);
	printf("%s\n", full);
	free(full);

	/* with two strings, and an empty third */
	full = concat_three(first, middle, empty);
	printf("%s\n", full);
	free(full);

	/* with only empty strings */
	full = concat_three(empty, empty, empty);
	printf("%s\n", full);
	free(full);

	return (0);
}
