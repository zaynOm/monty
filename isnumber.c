#include "monty.h"

/**
 * isnumber - checks if a string is a valid number
 * @s: string to check
 *
 * Return: true if @s is a valid number, otherwise false
*/
bool isnumber(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] != '-' && !isdigit(s[i]))
			return (false);
		i++;
	}
	return (true);
}
