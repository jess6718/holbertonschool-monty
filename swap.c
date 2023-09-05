#include "monty.h"

/**
 * swapping - Swaps the top two elements in a stack
 *
 * @stack: The stack
 * @line_number: Line number of current command
 *
 * Return: Void
 */
void swapping(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *head;
	size_t length;
	unsigned int i;

	i = line_number

	length = stack_length(*stack);

	if (length < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", i);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	temp = head->n;
	head->n = head->next->n;
	head->next->n = temp;
}

/**
 * stack_length - Determines the length of the stack
 *
 * @head: Head of the stack
 *
 * Return: Number of nodes in the stack
 */
size_t stack_length(stack_t *head)
{
	size_t size;
	stack_t *temp;

	size = 0;
	temp = head;

	while (temp != NULL)
	{
		temp = temp->next;
		size = size + 1;
	}
	return (size);
}
