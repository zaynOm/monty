#include "monty.h"

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
