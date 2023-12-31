#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef unsigned int ui;

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

/**
 * enum format - data format
 * @QUEUE: (FIFO)
 * @STACK: (LIFO)
 */
typedef enum format
{
	QUEUE,
	STACK
} format;

/**
 * struct monty - wraps data to free it easaly
 * @f: monty opcode file
 * @top: top of the stack
 * @line: readed line from the file
 * @format: data format of the DS (stack or queue)
 *
 * Description: this struct is gonna be used as a global variable
 * to make freeing memory more easy
*/
typedef struct monty
{
	FILE *f;
	stack_t *top;
	char *line;
	format format;
} monty;

extern monty data;

/* error handling */
void invalid_instruction_err(char *op, int line);
void argument_err(void);
void malloc_err(void);
void open_err(char *);
void int_err(ui);
void pint_err(ui);
void pop_err(ui);
void div_by_zero_err(ui);
void short_stack_err(char *, ui);
void pchar_err(ui);
void pchar_oor_err(ui);


/* stack manipulation */
void (*get_opcode(char *op, int line_number)) (stack_t **, ui);
void push(stack_t **top, ui line_number);
void pall(stack_t **top, ui line_number);
void pint(stack_t **top, ui line_number);
void pop(stack_t **top, ui line_number);
void swap(stack_t **top, ui line_number);
void add(stack_t **top, ui line_number);
void nop(stack_t **stack, ui line_number);
void sub(stack_t **top, ui line_number);
void _div(stack_t **top, ui line_number);
void mul(stack_t **top, ui line_number);
void mod(stack_t **top, ui line_number);
void pchar(stack_t **top, ui line_number);
void pstr(stack_t **top, ui line_number);
void rotl(stack_t **top, ui line_number);
void rotr(stack_t **top, ui line_number);

void free_stack(stack_t **head);
void freeall(int);
void queue(stack_t **top, ui line_number);
void stack(stack_t **top, ui line_number);


int is_number(char *s);

#endif /* MONTY_H */
