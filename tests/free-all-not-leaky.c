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
	int *nums;
	char **names;
	int num_count, name_count, i;

	num_count = 3;
	name_count = 2;

	nums = (int *)malloc(num_count * sizeof(int));
	for (i = 0; i < num_count; i++)
	{
		nums[i] = 5;
	}

	names = (char **)malloc(name_count * sizeof(char **));
	names[0] = "Jordan";
	names[1] = "Li";

	_free_all(2, nums, names);
	return (0);
}
