#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @top: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void add(stack_t **top, uint line_number)
{
	stack_t *tmp;

	if (!*top || !(*top)->next)
		add_err(line_number);

	(*top)->next->n += (*top)->n;
	tmp = *top;
	*top = (*top)->next;
	free(tmp);
}

/**
 * nop - does nothing
 * @top: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void nop(stack_t **top, uint line_number)
{
	(void)top;
	(void)line_number;
}

/**
 * sub - subtracts the top two elements of the stack
 * @top: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void sub(stack_t **top, uint line_number)
{
	stack_t *tmp;

	if (!*top || !(*top)->next)
		sub_err(line_number);

	(*top)->next->n -= (*top)->n;
	tmp = *top;
	*top = (*top)->next;
	free(tmp);
}

/**
 * mul - multiplies the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void mul(stack_t **stack, uint line_number)
{
	int product;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	product = (*stack)->next->n * (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = product;
	free(temp);
}

/**
 * mod - Computes the remainder of the second top element of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void mod(stack_t **stack, uint line_number)
{
	int remainder;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	remainder = (*stack)->next->n % (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = remainder;
	free(temp);
}
