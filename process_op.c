#include "monty.h"

/**
 * process_op - Matches user input command with system command
 *
 * @stack: The stack heap
 * @line_numebr: The number being adding onto the stack
 *
 * Return: void
 */
void (*process_op(char *op))(stack_t **stack, unsigned int line_number)
{
        int i = 0;
        instruction_t op_ins[] = {
                {"push", push},
                {"pall", pall},
                {"pint", pint},
                {"swap", swap},
                {"pop", pop},
                {"add", add},
                {"nop", nop},
                {NULL, NULL}
        };
        while (op_ins[i].opcode != NULL)
        {
                if (strcmp(op, op_ins[i].opcode) == 0)
                {
                        return (op_ins[i].f);
                }
                i = i + 1;
        }
        fprintf(stderr, "L<%d>: unknown instruction <%s>\n", line_number, op);
        exit(EXIT_FAILURE);
}
