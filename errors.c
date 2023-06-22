#include "monty.h"

/**
 * op_error - handels error related to stask manipulation
 * @code: error code
 * @line: line number where the error appears
 * @op: opcode
 */
void op_error(int code, int line, char *op)
{
	char *errors[] = {"L%u: usage: push integer\n",
		"L%u: can't pint, stack empty\n", "L%u: unknown instruction %s"};

	fprintf(stderr, errors[code], line, op);
	exit(EXIT_FAILURE);
}

/**
 * simple_error - handels simple errors
 * @code: error code
 */
void simple_error(int code)
{
	char *errors[] = {"USAGE: monty file\n", "Error: malloc failed\n"};

	fprintf(stderr, errors[code]);
	exit(EXIT_FAILURE);
}
