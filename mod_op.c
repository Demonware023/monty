#include "monty.h"

/**
  * mod_op - Computes the rest of the division of the second top-
  *          -element of the stack by the top element of the stack.
  * @head: pointer to the head of the stack
  * @line_number: keeps track of the lines in the monty files.
  *
  * Return: void
  */

void mod_op(stack_t **head, unsigned int line_number)
{
	stack_t *temp = var.head;
	(void)head;

	if (!temp || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		want_to_be_free();
		err();
	}
	else
	{
		var.head = var.head->next;
		if (temp->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			free(temp);
			exit(EXIT_FAILURE);
		}

		var.head->n = var.head->n % temp->n;
		free(temp);
	}
}
