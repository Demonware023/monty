#include "monty.h"

/**
  * div_op - divides the second top element of the stack by the top.
  * @head: pointer to head of the stack
  * @line_number: tracks the line number of the monty_file.
  *
  * Return: void
  */
void div_op(stack_t **head, unsigned int line_number)
{
	stack_t *temp = var.head;
	(void)head;

	if (!temp || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
		var.head->n /= temp->n;
		free(temp);
	}
}
