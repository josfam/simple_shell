#include "shell.h"

/**
 * _atoi - Converts a string to an int.
 * @str: The string to convert into an int.
 * Description: Converts a string to an int.
 * Return: The int that resulted from the string conversion.
*/
int _atoi(char *str)
{
	int multiplier, final_num, str_len, has_sign, sign, i;

	str_len = _strlen(str);
	multiplier = 1;
	final_num = 0;

	/* handle signed numbers */
	if (str[0] == '+' || str[0] == '-')
	{
		sign = (str[0] == '+') ? 1 : -1;
		has_sign = 1;
	}
	else
	{
		has_sign = 0;
		sign = 1;
	}

	for (i = str_len - 1; i >= 0 ; i--)
	{
		/* do not multiply the sign itself */
		if (i == 0 && has_sign)
			break;
		final_num += (str[i] - '0') * multiplier;
		multiplier *= 10;
	}

	return (sign * final_num);
}

/**
 * _is_number - Checks if the given string represents a number.
 * @str: The string to check.
 * Description: Checks if the given string represents a number.
 * Return: 1 if the string represents a number, 0 otherwise (i.e.
 *         if not every character is a number)
*/
int _is_number(char *str)
{
	while (*str)
	{
		if (!_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
