#include "monty.h"

/**
 * op_error - handels error related to stask manipulation
 * @code: error code
 * @line: line number where the error appears
 */
void op_error(int code, int line)
{
	char *errors[] = {"L%u: usage: push integer\n",
		"L%u: can't pint, stack empty\n"};
	char msg[100];

	sprintf(msg, errors[code], line);
	dprintf(stderr, "%s", msg);
	exit(EXIT_FAILURE);
}

/**
 * simple_error - handels simple errors
 * @code: error code
 */
void simple_error(int code)
{
	char *errors[] = {"USAGE: monty file\n", "Error: malloc failed\n"};

	dprintf(stderr, "%s", errors[code]);
	exit(EXIT_FAILURE);
}

/**
 * invalid_instruction_err - handels invalid instruction error
 * @op: invalid opcode
 * @line: line number where the error appears
*/
void invalid_instruction_err(char *op, int line)
{
	dprintf(stderr, "L%u: unknown instruction %s\n", line, op);
	exit(EXIT_FAILURE);
}
