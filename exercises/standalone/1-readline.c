#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "exercise.h"

int main(void)
{
	char *input_buff;
	ssize_t chars_read;
	size_t buff_size;
	
	/* setup defaults */
	input_buff = NULL;
	chars_read = 0;
	buff_size = 0;

	while(1)
	{
		/* show the prompt*/
		_puts("$ ");

		chars_read = getline(&input_buff, &buff_size, stdin);

		/* Handle fault, or EOF signal */
		if (chars_read == -1)
		{
			free(input_buff);
			break;
		}

		/* re-print the user input */
		_puts(input_buff);
	}
	_puts("\n");

	return (0);
}
