#include "monty.h"


void op_error(int code, int line)
{
    char *errors[] = {"L%u: usage: push integer\n", "L%u: can't pint, stack empty\n"};
    fprintf(stderr, errors[code], line);
    exit(EXIT_FAILURE);
}

void simple_error(int code)
{
    char *errors[] = {"USAGE: monty file\n", "Error: malloc failed\n"};
    fprintf(stderr, errors[code]);
	exit(EXIT_FAILURE);
}