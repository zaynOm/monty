#include "monty.h"

/**
 * swap - swaps the top two elements of a stack
 * @top: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void swap(stack_t **top, uint line_number)
{
	int tmp;

	if (!*top || !(*top)->next)
		short_stack_err("swap", line_number);

	tmp = (*top)->n;
	(*top)->n = (*top)->next->n;
	(*top)->next->n = tmp;
}
