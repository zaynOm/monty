#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef unsigned int ui;

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
void invalid_instruction_err(char *op, int line);

void argument_err(void);
void malloc_err(void);
void open_err(char *);
void int_err(ui);
void pint_err(ui);
void pop_err(ui);
void swap_err(ui);
void add_err(ui);
void sub_err(ui);

/* stack manipulation */
void (*get_opcode(char *op, int line_number)) (stack_t **, ui);
void push(stack_t **top, ui line_number);
void pall(stack_t **top, ui line_number);
void pint(stack_t **top, ui line_number);
void pop(stack_t **top, uint line_number);
void swap(stack_t **top, uint line_number);
void free_stack(stack_t **head);


int is_number(char *s);

#endif /* MONTY_H */
