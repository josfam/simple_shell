#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#include "exercise.h"

/**
 * _str_split - Splits a string and returns an array of each word
 *              of the string.
 * @to_split: The string to be split.
 * Description: Splits a string and returns an array of each word
 *              of the string.
 * Return: An array of each word of the string.
 */
char **_str_split(char *to_split)
{
	const int MAX_WORDS_TO_STORE = 20;
	char *str, *word;
	int words_stored;
	char **words; /* array of pointers to each word (token) */

	/* make a writable copy */
	str = strdup(to_split);

	words = (char **)malloc(sizeof(char *) * MAX_WORDS_TO_STORE);
	words_stored = 0;

	/* populate the array of pointers to each word */
	while (words_stored < MAX_WORDS_TO_STORE)
	{
		word = strtok(str, " ");
		words[words_stored] = word;

		str = NULL;

		if (!word)
			break;

		words_stored++;
	}

	return (words);
}
