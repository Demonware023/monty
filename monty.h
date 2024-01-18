#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
  * struct variable_a - global variables in struct.
  * @monty_file: file descriptor
  * @buffer: buffer
  * @head: points to the head of the list.
  *
  * Description: using global variables and extern.
  */
typedef struct variable_a
{
	FILE *monty_file;
	char *buffer;
	stack_t *head;
} variable_b;

extern variable_b var;
variable_b var;

/* Gets line in the struct*/
void get_func(unsigned int line_number);

/* Frees struct*/
void want_to_be_free(void);

/* Error handling*/
void err(void);

/* Getline function declaration*/
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/* Push item into stack operation*/
void push_op(stack_t **head, unsigned int line_number);

/* Print all items in the doubly linked list stack*/
void pall_op(stack_t **head, unsigned int line_number);

/* Prints the value at the top of the stack*/
void pint_op(stack_t **head, unsigned int line_number);

/* Removes the top element of the stack*/
void pop_op(stack_t **head, unsigned int line_number);

/* Swaps the top two elements of the stack*/
void swap_op(stack_t **head, unsigned int line_number);

/* Adds the top two elements of the stack*/
void add_op(stack_t **head, unsigned int line_number);

/* Does nothing*/
void nop_op(stack_t **head, unsigned int line_number);

/* Subtracts the top element of the stack from the second top element*/
void sub_op(stack_t **head, unsigned int line_number);

/* Divides the second element of the stack by the top element*/
void div_op(stack_t **head, unsigned int line_number);

/* Multiplies the second top element with the top element*/
void mul_op(stack_t **head, unsigned int line_number);

/* computes the rest of the division of the second top element of the-*/
/* -stack by the top element of the stack.*/
void mod_op(stack_t **head, unsigned int line_number);

#endif
