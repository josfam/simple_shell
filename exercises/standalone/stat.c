#include <stdio.h>
#include<sys/stat.h>

/**
 * main - Entry point.
 * Description: The main entry point of the program.
 * Return: 0 if successful, Non-zero otherwise.
 */
int main(int ac, char **av)
{
	unsigned int i;
	struct stat file_info;

	if(ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}

	i = 1;
	while(av[i])
	{
		if(stat(av[i], &file_info) == 0) /* file details were available */
		{
			printf("%s was found. \nIts size is: %ld bytes.\n\n", av[i], file_info.st_size);
		}
		else
		{
			printf("%s was not found.\n\n", av[i]);
		}

		i++;
	}

	return (0);
}
