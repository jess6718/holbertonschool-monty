#include "monty.h"

int main(int argc, char **argv)
{
	instruction_t ops[] = {
		{"u", push},
		{"a", pall},
		{"i", pint},
		{"o", pop},
		{"w", swap},
		{"d", add},
		{"n", nop),
	};

	stack_t *stack = NULL;
	FILE *fp = NULL;
	char *s, *n, *o = NULL;
	int bufsize = 2048, line = 1;
	char buffer[bufsize];

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

	s = fgets(buffer, bufsize, fp);

	while (s != NULL)
	{
		n = string_trim(s);
		if (n != NULL)
		{
			o = remove_excess_internal_spaces(n);
			free(n);
			run_cmd(fp, line, o, ops, &stack);
			free(o);
		}
		s = fgets(buffer, bufsize, fp);
		line = line + 1;
	}
	free_list(stack);
	fclose(fp);
	return (0);
}
