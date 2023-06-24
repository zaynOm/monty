#include "monty.h"

monty data = {NULL};

/**
 * main - entry point
 * @ac: arguments count
 * @av: list of arguments
 *
 * Return: 0 on seccess, 1 on failure
*/
int main(int ac, char **av)
{
	void (*fun)(stack_t **, ui);
	int bytes = 0, line_num = 0;
	size_t len = 0;
	char *op = NULL;

	if (ac != 2)
		argument_err();

	data.f = fopen(av[1], "r");

	if (!data.f)
		open_err(av[1]);

	while ((bytes = getline(&data.line, &len, data.f)) != EOF)
	{
		op = strtok(data.line, "\n\t\r ");
		line_num++;

		if (!op || op[0] == '#')
			continue;

		fun = get_opcode(op, line_num);
		fun(&data.top, line_num);
	}

	freeall(0);
	return (0);
}
