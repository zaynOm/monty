#include "monty.h"

/**
 * _div - divides the second top element of the stack from the top element
 * @top: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void _div(stack_t **top, ui line_number)
{
	stack_t *tmp;

	tmp = *top;

	if (!tmp || !tmp->next)
		short_stack_err("div", line_number);

	if (tmp->n == 0)
		div_by_zero_err(line_number);

	tmp->next->n /= tmp->n;
	*top = tmp->next;

	free(tmp);
}
