#include "monty.h"

void want_to_be_free(stack_t **stack)
{
	if (stack == NULL || (*stack) == NULL)
	{
		return;
	}

	want_to_be_free(&((*stack)->next));
	free(*stack);
	*stack = NULL;
}
