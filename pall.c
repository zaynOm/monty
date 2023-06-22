#include "monty.h"

void pall(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = *top;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	
}