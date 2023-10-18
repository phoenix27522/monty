#include "monty.h"
global_v global = {NULL, NULL, NULL, 1};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *line;
	FILE *fopcode;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stk_que = NULL;
	unsigned int line_n = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fopcode = fopen(argv[1], "r");
	global.fopcode = fopcode;
	if (!fopcode)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		line = NULL;
		read_line = getline(&line, &size, fopcode);
		global.line = line;
		line_n++;
		if (read_line > 0)
		{
			execute(line, &stk_que, line_n, fopcode);
		}
		free(line);
	}
	free_list(stk_que);
	fclose(fopcode);
return (0);
}
