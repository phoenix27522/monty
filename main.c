#include "monty.h"
/**
 * main - monty bytecode interpreter
 * @argc: argument count
 * @argv: the arguments array
 * Return: 0 if success or exit with EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	FILE *fopcode;
	instruction_t op[] = {
		{"push", op_push}, {"pall", op_pall}, {"pint", op_pint},
		{"pop", op_pop}, {"swap", op_swap}, {"add", op_add},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fopcode = fopen(argv[1], "r");
	if (fopcode == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	execute(fopcode, op);

	return (0);
}
/**
 * execute - executes each line in the file
 * @fopcode: the file to be looped
 * @op: pointer to the instructions struct
 * Return: Nothing
 */
void execute(FILE *fopcode, instruction_t *op)
{
	stack_t *stack = NULL;
	char line[1024];
	unsigned int line_number = 0;

	while (fgets(line, sizeof(line), fopcode) != NULL)
	{
		char *opcode;

		line_number++;
		if (line[0] == '#')
			continue;
		opcode = strtok(line, " \t\n$");
		if (opcode != NULL)
		{
			int i;
			int found = 0;

			for (i = 0; op[i].opcode != NULL; i++)
			{
				if (strcmp(opcode, op[i].opcode) == 0)
				{
					op[i].f(&stack, line_number);
					found = 1;
					break;
				}
			}
			if (found == 0)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				free_stack(&stack);
				exit(EXIT_FAILURE);
			}
		}
	}
	fclose(fopcode);
	free_stack(&stack);
}
