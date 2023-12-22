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
	char *first, *last, *friend;
	char *altogether;

	first = "Jordan";
	last = "Li";
	friend = "Marie";
	altogether = concat_all(6, first, " ", last, " & ", friend, ".");

	printf("%s\n", altogether);
	free(altogether);
}
