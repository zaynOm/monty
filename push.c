#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @top: top of the stack
 * @line_number: current line number in the file
 */
void push(stack_t **top, ui line_number)
{
	stack_t *new, *tmp;
	char *num;
	(void) line_number;

	new = malloc(sizeof(stack_t));
	if (!new)
		malloc_err();

	num = strtok(NULL, "\n\t\r ");
	if (!num || is_number(num))
		int_err(line_number);

	new->n = atoi(num);
	new->next = NULL;
	new->prev = NULL;

	if (!*top)
		*top = new;
	else if (data.format == STACK)
	{
		new->next = *top;
		(*top)->prev = new;
		*top = new;
	}
	else
	{
		tmp = *top;
		while (tmp->next)
			tmp = tmp->next;

		tmp->next = new;
		new->prev = tmp;
	}
}
