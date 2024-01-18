#include "monty.h"

/**
  * want_to_be_free - frees the struct var
  *
  * Return: void
  */

void want_to_be_free(void)
{
	stack_t *temp = var.head;

	while (temp)
	{
		var.head = var.head->next;
		free(temp);
		temp = var.head;
	}

	if (var.buffer != NULL)
	{
		free(var.buffer);
	}
}
