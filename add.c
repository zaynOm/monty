#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @top: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void add(stack_t **top, uint line_number)
{
	stack_t *tmp;

	if (!*top || !(*top)->next)
		short_stack_err("add", line_number);

	(*top)->next->n += (*top)->n;
	tmp = *top;
	*top = (*top)->next;
	free(tmp);
}
