#include "monty.h"

/**
  * add_op - The opcode adds the top two elements of the stack.
  * @head: head of the stack.
  * @line_number: line number to track errors
  *
  * Return: void
  */

void add_op(stack_t **head, unsigned int line_number)
{
	stack_t *temp = var.head;
	(void)head;

	if (!temp || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		want_to_be_free();
		err();
	}
	else
	{
		var.head = var.head->next;
		var.head->n = var.head->n + temp->n;
		free(temp);
	}
}
