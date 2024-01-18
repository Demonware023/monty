#include "monty.h"

void pall_op(stack_t **head, unsigned int line_number)
{
	stack_t *temp = var.head;
	(void)head;
	(void)line_number;

	if (temp == NULL)
	{
		return;
	}

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
