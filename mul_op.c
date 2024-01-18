#include "monty.h"

/**
  * mul_op - Multiplies the second top element with the top element.
  * @head: head of the stack.
  * @line_number: tracks the line number of the monty_file.
  *
  * Return: void
  */
void mul_op(stack_t **head, unsigned int line_number)
{
	stack_t *temp = var.head;
	(void)head;

	if (!temp || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		want_to_be_free();
		err();
	}

	var.head = var.head->next;
	var.head->n *= temp->n;
	free(temp);
}
