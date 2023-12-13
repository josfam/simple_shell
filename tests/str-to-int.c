#include <stdio.h>
#include "../shell.h"
#include <stdlib.h>

/**
 * main - Entry point.
 * Description: The main entry point of the program.
 * Return: 0 if successful, Non-zero otherwise.
 */
int main(void)
{
	int arr_len, i;

	char *nums[6] = {"0", "-0", "2", "500", "-800", ""};
	arr_len = 6;

	for (i = 0; i < arr_len; i++)
	{
		printf("%s\t| %s\n\n", "_atoi", "atoi");
		printf("%d\t| %d\n", _atoi(nums[i]), atoi(nums[i]));
		printf("%d\t| %d\n", (_atoi(nums[i]) + 10), (atoi(nums[i]) + 10));
		printf("---------------\n\n");
	}

	return (0);
}
