#include <stdarg.h>
#include <stdlib.h>
#include "shell.h"

/**
 * _free_all - Frees all memory locations provided.
 * @how_many: How many locations to free.
 * Description: Frees all memory locations provided.
*/
void _free_all(int how_many, ...)
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
