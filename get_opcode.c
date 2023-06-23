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
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
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
