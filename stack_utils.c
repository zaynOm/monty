#include "monty.h"

/**
 * free_stack - Frees a stack from memory
 * @head: Pointer to the head of the stack
 */
void free_stack(stack_t **head)
{
	stack_t *temp;

	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

/**
 * freeall - frees all allocated memory
 * @exit_code: the exit code
*/
void freeall(int exit_code)
{
	fclose(data.f);
	free(data.line);
	free_stack(&data.top);
	exit(exit_code);
}

/**
 * stack - Sets the data format to STACK
 * @top: pointer to the head of the stack
 * @line_number: current line number in the file
 */
void stack(stack_t **top, ui line_number)
{
	(void) top;
	(void) line_number;
	data.format = STACK;
}

/**
 * queue - Sets the data format to QUEUE
 * @top: pointer to the head of the stack
 * @line_number: current line number in the file
 */
void queue(stack_t **top, ui line_number)
{
	(void) top;
	(void) line_number;
	data.format = QUEUE;
}
