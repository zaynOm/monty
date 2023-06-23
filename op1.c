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
		simple_error(MALLOC_FAILED);

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

/**
 * pall - prints all the values on the stack, starting from the top
 * @top: top of the stack
 * @line_number: current line number in the file
 */
void pall(stack_t **top, ui line_number)
{
	stack_t *tmp = *top;
	(void) line_number;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	fflush(stdout);
}

/**
 * pint -  prints the value at the top of the stack
 * @top: top of the stack
 * @line_number: current line number in the file
 */
void pint(stack_t **top, ui line_number)
{
	if (!*top)
		op_error(CANT_PRINT_EMPTY_STACK, line_number);

	printf("%d\n", (*top)->n);
}
