#include "monty.h"

void pall_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;

	for (temp = *stack ; temp != NULL ; temp = temp->next)
	{
		printf("%d\n", temp->n);
	}
}
