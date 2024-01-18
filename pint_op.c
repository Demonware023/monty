#include "monty.h"

/**
  * pint_op - Prints the top element of the stack.
  *
  * @head: head of the stack.
  *
  * @line_number: line number tracking errors.
  *
  * Return: void
  */

void pint_op(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		want_to_be_free();
		err();
	}
	else
	{
		printf("%d\n", (*head)->n);
	}
}
