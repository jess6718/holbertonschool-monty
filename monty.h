#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void run_command(char *opcode, stack_t **stack, unsigned int line_number);

void pushing(stack_t **stack, unsigned int line_number);
void palling(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void pinting(stack_t **stack, unsigned int line_number);
void popping(stack_t **stack, unsigned int line_number);
void swapping(stack_t **stack, unsigned int line_number);
void adding(stack_t **stack, unsigned int line_number);
void nopping(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number);
void subbing(stack_t **stack, unsigned int line_number);

size_t stack_length(stack_t *head);

void free_stack(stack_t *stack);

#endif
