#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stddef.h>
#include "shell.h"

/**
 * _get_prompt_input - Shows a terminal prompt, and gets terminal
 *                    inputs provided at said prompt.
 * Description: Shows a terminal prompt, and gets terminal
 *              inputs provided at said prompt.
 *              If no input is provided, the user is re-prompted.
 *              If CTRL+D is pressed, the program terminates.
 * Return: The input entered (if any), or NULL on error.
*/
char *_get_prompt_input(void)
{
	ssize_t chars_read;
	char *input_buff;
	size_t buff_size;

	/* setup defaults for getline */
	chars_read = 0;
	input_buff = NULL;
	buff_size = 0;

	while (1)
	{
		/* show the prompt */
		_puts("($) ");

		chars_read = getline(&input_buff, &buff_size, stdin);

		/* error and EOF handling */
		if (chars_read == -1)
		{
			free(input_buff);
			return (NULL);
		}

		/* re-prompt if no input was provided */
		if (chars_read == 1)
			continue;
		else
			break;
	}

	/* replace the newline added by getline, for execve's sake */
	if (input_buff[chars_read - 1] == '\n')
		input_buff[chars_read - 1] = '\0';

	return (input_buff);
}