#include "monty.h"

int num;

/**
 * main - entry point
 * @ac: arguments count
 * @av: list of arguments
 *
 * Return: 0 on seccess, 1 on failure
*/
int main(int ac, char **av)
{
	FILE *f;
	char buff[100];
	stack_t *top = NULL;
	void (*fun)(stack_t **, ui);
	int bytes, line_num = 0;
	size_t len = 0;
	char *line = NULL, *op = NULL, *data = NULL;


	if (ac != 2)
		simple_error(PROG_USAGE);

	f = fopen(av[1], "r");

	while ((bytes = getline(&line, &len, f)) != EOF)
	{
		strcpy(buff, line);
		op = strtok(buff, "\n\t\r ");
		data = strtok(NULL, "\n\t\r ");
		line_num++;

		if (!strcmp(op, "push"))
		{
			if (!data || !isnumber(data))
				op_error(NOT_INT_FOR_PUSH, line_num);
			num = atoi(data);
		}
		fun = get_opcode(op, line_num);
		fun(&top, line_num);
	}

	fclose(f);
	free(line);
	return (0);
}
