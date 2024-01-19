#include "monty.h"

void pop_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(file);
		want_to_be_free(stack);
		exit(EXIT_FAILURE);
	}
	*stack = temp->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}
