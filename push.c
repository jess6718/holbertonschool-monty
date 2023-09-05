#include "monty.h"

/**
 * pushing - Pushes new number to top of stack
 *
 * @stack: The stack
 * @line_number: Number to be pushed
 *
 * Return: Void
 */
void pushing(stack_t **stack, unsigned int line_number)
{
	stack_t *NewNode;
	char *token;
	int value;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	token = strtok(NULL, " \t\r\n'$'");

	if (token == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(token);

	if (strspn(token, "0123456789+-") != strlen(token))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	NewNode = malloc(sizeof(stack_t));

	if (NewNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	NewNode->n = value;
	NewNode->prev = NULL;
	NewNode->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = NewNode;
	}
	*stack = NewNode;
}
