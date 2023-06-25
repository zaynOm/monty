#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 * @top: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void rotl(stack_t **top, ui line_number)
{
	stack_t *tmp, *last = *top;
	(void)line_number;

	if (!last || !last->next)
		return;

	while (last->next)
		last = last->next;

	tmp = *top;
	*top = tmp->next;
	tmp->next = NULL;
	last->next = tmp;
	tmp->prev = last;
}
