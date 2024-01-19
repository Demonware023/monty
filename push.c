#include "monty.h"

void push(stack_t **stack, unsigned int line_number, char *pushnum)
{
	if (strcmp(pushnum, "0") == 0)
	{
		(*stack)->n = 0;
	}
	if (strcmp(pushnum, "0") != 0)
	{
		(*stack)->n = atoi(pushnum);
		if ((*stack)->n == 0 || (pushnum[0] != '-' && (*stack)->n == -1))
		{
			fprintf(stderr, "Error: L%d: usage: push integer\n", line_number);
			want_to_be_free(stack);
			err();
		}
	}
}
