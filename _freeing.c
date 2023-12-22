#include <stdarg.h>
#include <stdlib.h>
#include "shell.h"

/**
 * free_all - Frees all memory locations provided.
 * @how_many: How many locations to free.
 * Description: Frees all memory locations provided.
 *              Works for straight-forward memory locations,
 *              i.e. blocks of memory that do not themselves
 *              contain pointers to other blocks of memory
 *              (like an array of pointers to other memory).
*/
void free_all(int how_many, ...)
{
	int i;
	void *memory;
	va_list args;

	va_start(args, how_many);

	/* free all memory locations given*/
	for (i = 0; i < how_many; i++)
	{
		memory = va_arg(args, void *);

		if (memory != NULL)
		{
			free(memory);
		}
	}

	va_end(args);
}

/**
 * free_tokens - Frees memory allocated for storing tokens.
 * @tokens: The array of tokens, which to free.
 * Description: Frees memory allocated for storing tokens.
 * Return: Nothing.
*/
void free_tokens(char **tokens)
{
	free_arr(tokens);
}

/**
 * free_arr - Frees memory allocated in an array of pointers.
 * @arr: The array of pointers, which to free.
 * Description: Frees memory allocated in an array of pointers.
 * Return: Nothing.
*/
void free_arr(char **arr)
{
	int i;

	i = 0;
	for (i = 0; arr[i] != NULL; i++)
	{
		free(arr[i]);
	}

	free(arr);
}
