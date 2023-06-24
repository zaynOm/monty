#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * @top: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void rotr(stack_t **top, ui line_number)
{
	stack_t *tmp = *top;
	int num;
	(void)line_number;

	if (!tmp || !tmp->next)
		return;

	while (tmp->next)
		tmp = tmp->next;

	num = (*top)->n;
	(*top)->n = tmp->n;
	tmp->n = num;
}
