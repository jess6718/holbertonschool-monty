#include "monty.h"

/**
 * pinting - Prints the value at the top of the stack, followed by the new line
 *
 * @stack: Pointer to a pointer to the top of the stack
 * @line_number: Line number of the command
 *
 * Return: Void
 */
void pinting(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}
