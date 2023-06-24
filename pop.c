#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @top: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void pop(stack_t **top, uint line_number)
{
	stack_t *temp;

	if (*top == NULL)
		pop_err(line_number);

	temp = *top;
	*top = (*top)->next;
	free(temp);
}
