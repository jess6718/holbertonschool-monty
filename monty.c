#include "monty.h"

/**
 * main - The Monty Code
 *
 * @argc: The number of arguments
 * @argv: The argument vector
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *fp;
	stack_t *stack = NULL;
	ssize_t read;
	size_t len = 0;
	char *opcode, *line = NULL;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read = getline(&line, &len, fp);

	while (read != -1)
	{
		opcode = strtok(line, " \t\r\n'$'");
		if (opcode == NULL)
		{
			line_number = line_number + 1;
			read = getline(&line, &len, fp);
			continue;
		}
		run_command(opcode, &stack, line_number);
		read = getline(&line, &len, fp);
		line_number = line_number + 1;
	}
	free(line);
	free_stack(stack);
	fclose(fp);
	return (EXIT_SUCCESS);
}
