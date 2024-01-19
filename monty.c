#include "monty.h"

FILE *file = NULL;

int main(int argc, char **argv)
{
	void (*f)(stack_t **, unsigned int) = NULL;

	char *buffer = NULL, op[50] = {'\0'}, pushnum[50] = {'\0'}, *token = NULL;
	size_t bufsize = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if  (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
		file = fopen(argv[1], "r");
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (; getline(&buffer, &bufsize, file) != EOF ; line_number++)
	{
		token = strtok((buffer), " \t\n");
		if (token == NULL)
		{
			free(buffer), buffer = NULL;
			continue;
		}
		strcpy(op, token);
		f = get_func(&stack, line_number, op);
		if (f == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			err();
		}
		if (strcmp(op, "push") == 0)
		{
			token = strtok(NULL, " \t\n");
			if (token == NULL)
			{
				free(buffer), buffer = NULL, want_to_be_free(&stack);
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				err();
			}
			strcpy(pushnum, token);
		}
		free(buffer), buffer = NULL;
		f(&stack, line_number);
		
		if (strcmp(op, "push") == 0)
		{
			push(&stack, line_number, pushnum);
		}
	}
	free(buffer), fclose(file), want_to_be_free(&stack);
	
	return (EXIT_SUCCESS);
}
