#include "monty.h"

/**
  * sub_op - subtracts the first two/top elements of the stack.
  * @head: head of the stack
  * @line_number: tracks the lines of the monty file
  *
  * Return: void
  */

void sub_op(stack_t **head, unsigned int line_number)
{
	stack_t *temp = var.head;
	(void)head;

	if (!temp || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		want_to_be_free();
		err();
	}
	else
	{
		var.head = var.head->next;
		var.head->n -= temp->n;
		free(temp);
	}
}
