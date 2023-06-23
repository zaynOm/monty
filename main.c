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
	int bytes = 0, line_num = 0;
	size_t len = 0;
	char *line = NULL, *op = NULL, *data = NULL;

	if (ac != 2)
		argument_err();

	f = fopen(av[1], "r");

	if (!f)
		open_err(av[1]);

	while ((bytes = getline(&line, &len, f)) != EOF)
	{
		strcpy(buff, line);
		op = strtok(buff, "\n\t\r ");
		line_num++;

		if (!op)
			continue;

		if (!strcmp(op, "push"))
		{
			data = strtok(NULL, "\n\t\r ");
			if (!data || is_number(data))
				int_err(line_num);
			num = atoi(data);
		}
		fun = get_opcode(op, line_num);
		fun(&top, line_num);
	}

	fclose(f);
	free(line);
	free_stack(&top);
	return (0);
}
