#include "monty.h"

/**
 * mul - multiplies the top two elements of the stack
 * @top: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void mul(stack_t **top, ui line_number)
{
	stack_t *tmp;

	tmp = *top;

	if (!tmp || !tmp->next)
		short_stack_err("mul", line_number);
	tmp->next->n *= tmp->n;
	*top = tmp->next;

	free(tmp);
}
