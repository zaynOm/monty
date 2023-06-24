#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @top: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void pchar(stack_t **top, ui line_number)
{
	int num;

	if (!*top)
		pchar_err(line_number);

	num = (*top)->n;
	if (num < 0 || 127 < num)
		pchar_oor_err(line_number);

	printf("%c\n", num);
}
