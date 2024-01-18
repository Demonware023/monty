#include "monty.h"

void swap_op(stack_t **head, unsigned int line_number)
{
	stack_t *temp = var.head;
	(void)head;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		want_to_be_free();
		err();
	}
	else
	{
		var.head = var.head->next;
		var.head->prev = NULL;
		if(var.head->next == NULL)
		{
			var.head->next = temp;
			temp->next = NULL;
			temp->prev = var.head;
		}
		else
		{
			temp->next = var.head->next;
			var.head->next->prev = temp;
			var.head->next = temp;
			temp->prev = var.head;
		}
	}
}
