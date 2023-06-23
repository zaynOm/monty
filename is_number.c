#include "monty.h"

/**
 * is_number - checks if a string is a valid number
 * @s: string to check
 *
 * Return: true if @s is a valid number, otherwise false
*/
int is_number(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] != '-' && !isdigit(s[i]))
			return (-1);
		i++;
	}
	return (0);
}
