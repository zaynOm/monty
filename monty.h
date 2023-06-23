#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef unsigned int ui;

#define NOT_INT_FOR_PUSH 0
#define CANT_PRINT_EMPTY_STACK 1
#define INVALID_INSTRUCTION 2


#define PROG_USAGE 0
#define MALLOC_FIALED 1


extern int num;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, ui line_number);
} instruction_t;


/* error handling */
void op_error(int code, int line);
void simple_error(int code);
void invalid_instruction_err(char *op, int line);

/* stack manipulation */
void push(stack_t **top, ui line_number);
void pall(stack_t **top, ui line_number);
void pint(stack_t **top, ui line_number);
void (*get_opcode(char *op, int line_number)) (stack_t **, ui);


bool isnumber(char *s);

#endif /* MONTY_H */
