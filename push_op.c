#include "monty.h"

/**
  * push - push an new element onto the stack LIFO.
  * @stack: pointer to the stack structure.
  * @n: element to push to the stack.
  *
  * Return: newnode.
  */
void push_op(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		want_to_be_free(stack);
		exit(EXIT_FAILURE);
	}

	(void)line_number;
	
	if (*stack)
	{
		(*stack)->prev = new;
	}
	
	new->prev = NULL;
	new->next = *stack;
	new->n = 0;
	*stack = new;
}
