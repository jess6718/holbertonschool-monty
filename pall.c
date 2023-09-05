#include "monty.h"

/**
 * palling - Prints all values in the stack
 *
 * @stack: Stack to be printed
 * @line_number: Number after command
 *
 * Return: Void
 */
void palling(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
