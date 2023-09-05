#include "monty.h"

/**
 * run_command - Runs the command on the line
 *
 * @opcode: Pointer to the opcode
 * @stack: Pointer to top of the stack
 * @line_number: Line number of the line being read
 *
 * Return: Void
 */
void run_command(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t instructions[] = {
		{"push", pushing},
		{"pall", palling},
		{"pint", pinting},
		{NULL, NULL}
	};

	i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i = i + 1;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
