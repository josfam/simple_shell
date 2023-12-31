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
	char *first, *middle, *last, *full, *empty;

	first = "Jordan";
	middle = " Marie";
	last = " Li";
	empty = "";

	full = concat_three(first, middle, last);
	printf("%s\n", full);
	free(full);

	/* called with three args, one of which is empty */
	full = concat_three(first, last, empty);
	printf("%s\n", full);
	free(full);

	/* called with all empty args */
	full = concat_three(empty, empty, empty);
	printf("%s\n", full);
	free(full);
}
