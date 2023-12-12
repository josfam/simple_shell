#include <stdio.h>
#include "../shell.h"

/**
 * main - Entry point.
 * Description: The main entry point of the program.
 * Return: 0 if successful, Non-zero otherwise.
 */
int main(void)
{	
	int num_pairs, compared, i;
	char *s1, *s2;
	char *pairs[6][2] = {
		{"ABC", "ABC"},
		{"abc", "ab"},
		{"aba", "abz"},
		{"abj", "abc"},
		{"", ""},
		{"", "a"}
	};
	num_pairs = 6;

	for(i = 0; i < num_pairs; i++)
	{
		s1 = pairs[i][0];
		s2 = pairs[i][1];
		compared = _strcmp(s1, s2);

		if (compared == 0)
			printf("%s = %s\n", s1, s2);
		else if (compared == 1)
			printf("%s > %s\n", s1, s2);
		else
			printf("%s < %s\n", s1, s2);
	}

	return (0);
}
