#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/*-------------------- doubly linked list --------------------*/

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

/*-------------------- Struct --------------------*/

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/*-------------------- List --------------------*/

void free_stack(stack_t **h);

/*-------------------- Utility --------------------*/
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);

/*-------------------- Main --------------------*/

void execute(FILE *fopcode, instruction_t *op);

/*-------------------- op_function.c --------------------*/
void op_pall(stack_t **h, unsigned int line_n);
void op_push(stack_t **h, unsigned int line_n);
void op_pint(stack_t **h, unsigned int line_n);
void op_pop(stack_t **h, unsigned int line_n);
void op_swap(stack_t **h, unsigned int line_n);

#endif /* MONTY_H */
