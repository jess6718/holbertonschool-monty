#include "monty.h"

/**
 * subbing - subtractss top two nodes of the stack, store the total value
 * to second node and removes the top node
 *
 * @stack: pointer to pointer to top of the stack
 *
 * @line_number: line number of the line read
 */
void subbing(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	popping(stack, line_number);
}
