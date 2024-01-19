#include "monty.h"

void pint_op(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		want_to_be_free(stack);
		err();
	}

	printf("%d\n", (*stack)->n);
}
