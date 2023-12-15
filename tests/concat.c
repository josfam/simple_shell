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
	char *name;
	char *fuse1, *final;

	name = "Jor";
	fuse1 = concat_strs(name, "dan ");
	final = concat_strs(fuse1, "Lee");
	printf("%s\n", final);
	free(fuse1);
	free(final);
}
