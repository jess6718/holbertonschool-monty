#include "monty.h"

/**
 * free_list - Frees the list
 *
 * @head: List to be freed
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
