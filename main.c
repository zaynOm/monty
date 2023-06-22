#include "monty.h"


#define BUFFER_SIZE 1024
int num;

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

void push(stack_t **top, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		simple_error(MALLOC_FIALED);
	*new = (stack_t) {.n = num, .next = NULL, .prev = NULL};

	if (!*top)
		*top = new;
	else 
	{
		new->next = *top;
		(*top)->prev = new;
		*top = new;
	}
}
void pall(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = *top;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	
}

int main(int ac, char **av)
{
	FILE *f;
	char *line = NULL, *op = NULL, *data = NULL;
	size_t bytes, len = 0;
	stack_t *stack = NULL;
	int i, line_num = 0;
	instruction_t ops[] = {
		{"pall", pall},
		{"push", push},
		{NULL, NULL},
	};

	if (ac != 2)
		simple_error(PROG_USAGE);

	printf("reading file %s\n", av[1]);

	f = fopen(av[1], "r");
	while ((bytes = getline(&line, &len, f)) != -1)
	{
		char buff[100];
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
		while (ops[i].opcode)
		{
			if (!strcmp(op, ops[i].opcode))
			{
				ops[i].f(&stack, line_num);
				break;
			}
			i++;
		}
	}

	fclose(f);
	free(line);
	return (0);
}
