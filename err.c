#include "monty.h"

/**
  * err - Handles critic error & exit.
  *
  * @Return: void
  */

void err(void)
{
	fclose(var.monty_file);
	exit(EXIT_FAILURE);
}
