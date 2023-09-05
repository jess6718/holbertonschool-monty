#include "monty.h"

/**
 * popping - Removes the top element of the stack...or pop 
 * pop, pop you want it?
 *
 * @stack: The stack
 * @line_number: Line number of current command
 *
 * Return: Void
 */
void popping(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;

	if (temp->next != NULL)
	{
		temp->next->prev = NULL;
	}
	free(temp);
}
