#include "monty.h"

void add_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || !temp->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		want_to_be_free(stack);
		err();
	}

	temp->next->n += temp->n;
	*stack = temp->next;
	(*stack)->prev = NULL;
	free(temp);
}
