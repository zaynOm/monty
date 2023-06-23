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
		malloc_err();

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
		pint_err(line_number);

	printf("%d\n", (*top)->n);
}

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

/**
 * swap - swaps the top two elements of a stack
 * @top: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void swap(stack_t **top, uint line_number)
{
	int tmp;

	if (!*top || !(*top)->next)
		swap_err(line_number);

	tmp = (*top)->n;
	(*top)->n = (*top)->next->n;
	(*top)->next->n = tmp;
}
