#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @top: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void pstr(stack_t **top, ui line_number)
{
	stack_t *tmp = *top;
	int num;
	(void)line_number;

	while (tmp)
	{
		num = tmp->n;
		tmp = tmp->next;

		if (num == 0 || num < 0 || 127 < num)
			break;

		printf("%c", num);
	}

	printf("\n");
}
