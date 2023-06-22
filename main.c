#include "monty.h"

#define BUFF_SIZE 1024
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
	char *line = NULL, *op = NULL, *data = NULL;
	size_t bytes, len = 0;
	stack_t *stack = NULL;
	int i, line_num = 0;
	char buff[100];
	void (*fun)(stack_t **, ui);


	if (ac != 2)
		simple_error(PROG_USAGE);

	f = fopen(av[1], "r");

	while ((bytes = getline(&line, &len, f)) != -1)
	{

		i = 0;

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
		fun(&stack, line_num);
	}

	fclose(f);
	free(line);
	return (0);
}
