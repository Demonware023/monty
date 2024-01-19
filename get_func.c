#include "monty.h"

void (*get_func(stack_t **stack, int l, char *code))(stack_t **, unsigned int)
{
	int i = 0;

	instruction_t op[] = {
		{"push", push_op}, {"pall", pall_op},
		{"pint", pint_op}, {"pop", pop_op},
		{"swap", swap_op}, {"add", add_op},
		{"nop", nop_op}, {"sub", sub_op},
		{NULL, NULL}
	};

	while (strcmp(code, op[i].opcode) != 0)
	{
		i++;
		if (i > 7)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", l, code);
			want_to_be_free(stack);
			err();
		}
	}
	return (op[i].f);
}
