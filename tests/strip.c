#include "../shell.h"
#include <stdio.h>

/**
 * main - Entry point.
 * Description: The main entry point of the program.
 * Return: 0 if successful, Non-zero otherwise.
 */
int main(void)
{
	char *strs[5] = {
		"  /bin/ls  ", 
		"", 
		"   a", 
		"a   ",
		"   "
		};

	int strs_count, i;
	char *stripped;

	i = 0;
	strs_count = 5;

	for (i = 0; i < strs_count; i++)
	{
		stripped = _strip(strs[i]);
		printf("%s\t| len:%d\n", stripped, _strlen(stripped));
		printf("---------------\n");
	}
	return (0);
}
