#include "monty.h"

/**
  * pop_op - The opcode pop removes the top element of the stack.
  *
  * @head: head of the linked list/stack
  *
  * @line_number: void
  *
  * Return: void.
  */

void pop_op(stack_t **head, unsigned int line_number)
{
	stack_t *temp = var.head;
	(void)head;

	if (!head)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		want_to_be_free();
		err();
	}

	var.head = var.head->next;
	free(temp);
}
