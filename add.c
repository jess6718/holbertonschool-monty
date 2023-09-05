#include "monty.h"

/**
 * adding - adds top two nodes of the stack, store the total value to second 
 * node and removes the top node
 *
 * @stack: pointer to pointer to top of the stack
 *
 * @line_number: line number of the line read
 */
void adding(stack_t **stack, unsigned int line_number)
{
        if (stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        (*stack)->next->n = (*stack)->n + (*stack)->next->n;
        popping(stack, line_number);
}
