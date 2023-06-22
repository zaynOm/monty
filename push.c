#include "monty.h"

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