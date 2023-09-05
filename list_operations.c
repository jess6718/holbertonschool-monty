#include "monty.h"

/**
 * free_stack - Frees the list
 *
 * @stack: Stack to be freed
 *
 * Return: Void
 */
void free_stack(stack_t *stack)
{
	stack_t *NextStack;

	while (stack != NULL)
	{
		NextStack = stack->next;
		free(stack);
		stack = NextStack;
	}
}
