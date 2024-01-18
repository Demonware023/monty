#include "monty.h"

/**
  * get_func - Get function from op_list if found
  * @line_number: line number to track errors
  *
  * Return: void
  */

void get_func(unsigned int line_number)
{
	char *opcode = NULL;
	int i = 0;
	
	instruction_t op[] = {
		{"push", push_op}, {"pall", pall_op},
		{"pint", pint_op}, {"pop", pop_op},
		{"swap", swap_op}, {"add", add_op},
		{"nop", nop_op}, {"sub", sub_op},
		{"div", div_op}, {"mul", mul_op},
		{"mod", mod_op},
		{NULL, NULL}
	};
	opcode = strtok(var.buffer, " ");

	if (opcode != NULL && opcode[0] != '#')/* Skip comments*/
	{
		while (op[i].opcode)
		{
			if (strcmp(op[i].opcode, opcode) == 0)
			{
				op[i].f(&var.head, line_number);
				break;
			}
			i++;
		}
	}
	if (op[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		want_to_be_free();
		err();
	}
}
