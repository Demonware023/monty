#include <stdio.h>
#include "monty.h"

/**
  * main - Entry point to the program.
  * @argc: Argument count.
  * @argv: Argument vector.
  *
  * Return: 0 or 1
  */

int main(int argc, char **argv)
{
	ssize_t cread;
	size_t length = 0;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	var.monty_file = fopen (argv[1], "r");
	
	if (var.monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((cread = getline(&var.buffer, &length, var.monty_file)) != -1)
	{
		line_number++;
		if (var.buffer != NULL)
		{
			var.buffer[strlen(var.buffer) - 1] = '\0';
			get_func(line_number);
		}
	}
	want_to_be_free();
	exit(EXIT_SUCCESS);
}
