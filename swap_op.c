#include "monty.h"

void swap_op(stack_t **stack, unsigned int line_number)
{
	int temp = (*stack)->n;

	if (*stack == NULL || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(file);
		want_to_be_free(stack);
		exit(EXIT_FAILURE);
	}
	/* Stores the value of the second element in the first element.*/
	(*stack)->n = (*stack)->next->n;
	/* Assigns the temporarily stored value in temp to the second-*/
	/* -element ((*stack)->next->n) effectively completing the swap*/
	(*stack)->next->n = temp;
}
