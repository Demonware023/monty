#include "monty.h"

/**
  * push_op - pushes a new node to the top of the stack.
  * @head: Head pointer to the first item on top of the stack.
  * @line_number: Tracks lines on the monty_file.
  *
  * Return: void
  */

void push_op(stack_t **head, unsigned int line_number)
{
	stack_t *newnode = NULL;
	char *num = NULL;
	int n = 0, i = 0;
	(void)head;

	num = strtok(NULL, " \t\n");
	if (num == NULL)
	{
		fprintf(stderr, "L%u: usuage: push integer\n", line_number);
		want_to_be_free();
		exit(EXIT_FAILURE);
	}
	if (num[i] == '-')
	{
		i++;
	}
	for (; num[i]; i++)
	{
		if (num[i] < '0' || num[i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			want_to_be_free();
			exit(EXIT_FAILURE);
		}
	}
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		want_to_be_free();
		exit(EXIT_FAILURE);
	}
	n = atoi(num);
	newnode->n = n;
	newnode->prev = NULL;
	newnode->next = NULL;
	
	if (var.head == NULL)
	{
		var.head = newnode;
	}
	else
	{
		newnode->next = var.head;
		var.head->prev = newnode;
		var.head = newnode;
	}
}
