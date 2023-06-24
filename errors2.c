#include "monty.h"

/**
 * pint_err - This function prints the error message when pint fails.
 *
 * @line: Line number of the opcode.
 */

void pint_err(ui line)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line);
	 freeall(EXIT_FAILURE);
}

/**
 * pop_err - This function prints the error message when pop fails.
 *
 * @line: Line number of the opcode.
 */
void pop_err(ui line)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line);
	 freeall(EXIT_FAILURE);
}

/**
 * swap_err - This function prints the error message when swap fails.
 *
 * @line: Line number of the opcode.
 */
void swap_err(ui line)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line);
	 freeall(EXIT_FAILURE);
}

/**
 * add_err - This function prints the error message when add fails.
 *
 * @line: Line number of the opcode.
 */
void add_err(ui line)
{
	fprintf(stderr, "L%u: can't add, stack too short\n", line);
	 freeall(EXIT_FAILURE);
}

/**
 * sub_err - This function prints the error message when sub fails.
 *
 * @line: Line number of the opcode.
 */
void sub_err(ui line)
{
	fprintf(stderr, "L%u: can't sub, stack too short\n", line);
	 freeall(EXIT_FAILURE);
}
