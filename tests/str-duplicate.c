#include <stdio.h>
#include "../shell.h"

/**
 * main - Entry point.
 * Description: The main entry point of the program.
 * Return: 0 if successful, Non-zero otherwise.
 */
int main(void)
{
	char *original, *duplicate;

	original = "Hello, there!";
	duplicate = _strdup(original);
	printf("%s\n", duplicate);

	return (0);
}
