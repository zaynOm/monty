#include "monty.h"

/**
 * get_opcode - finds the function corresponding the opcode
 * @op: opcode
 * @line_number: current line number in the file
 *
 * Return: pointer to function
 */
void (*get_opcode(char *op, int line_number)) (stack_t **, ui)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", _push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL},
	};

	while (ops[i].opcode)
	{
		if (!strcmp(op, ops[i].opcode))
			return (ops[i].f);
		i++;
	}
	invalid_instruction_err(op, line_number);
	return (NULL);
}
