#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @top: top of the stack
 * @line_number: current line number in the file
*/
void push(stack_t **top, ui line_number)
{
	stack_t *new;
	(void) line_number;

	new = malloc(sizeof(stack_t));
	if (!new)
		simple_error(MALLOC_FIALED);
	/* *new = (stack_t) {.n = num, .next = NULL, .prev = NULL}; */
	new->n = num;
	new->next = NULL;
	new->prev = NULL;

	if (!*top)
		*top = new;
	else
	{
		new->next = *top;
		(*top)->prev = new;
		*top = new;
	}
}
