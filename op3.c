#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @top: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void pchar(stack_t **top, uint line_number)
{
	int c;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	c = (*top)->n;
	if (c < 0 || c > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", c);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @top: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void pstr(stack_t **top, uint line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *top;
	while (temp != NULL && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the stack to the left
 * @top: pointer to the head of the stack
 * @line_number: line number of the command being run (unused)
 */
void rotl(stack_t **top, uint line_number)
{
	stack_t *temp, *last;

	(void)(line_number);

	if (!*top || !(*top)->next)
		return;

	temp = *top;
	last = *top;

	while (last->next)
		last = last->next;

	*top = (*top)->next;
	(*top)->prev = NULL;

	temp->next = NULL;
	temp->prev = last;
	last->next = temp;
}

/**
 * rotr - Rotates the stack to the right
 * @top: pointer to the head of the stack
 * @line_number: line number of the command being run (unused)
 */
void rotr(stack_t **top, uint line_number)
{
	stack_t *temp, *last;

	(void)line_number;
	if (*top == NULL || (*top)->next == NULL)
		return;
	temp = *top;
	last = *top;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	temp->prev = last;
	last->next = temp;
	*top = last;
}

/**
 * _div - divides the second top element of the stack from the top element
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void _div(stack_t **stack, uint line_number)
{
	int quotient;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	quotient = (*stack)->next->n / (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = quotient;
	free(temp);
}
