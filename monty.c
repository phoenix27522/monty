#include "monty.h"
/**
* execute - executes the opcode
* @stk_que: head linked list - stack
* @line_n: line_counter
* @fopcode: poiner to monty file
* @line: line content
* Return: no return
*/
int execute(char *line, stack_t **stk_que, unsigned int line_n, FILE *fopcode)
{
	instruction_t op[] = {
				{"push", op_push}, {"pall", op_pall},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op_parsed;

	op_parsed = strtok(line, " \n\t");
	if (op_parsed && op_parsed[0] == '#')
		return (0);
	global.arg = strtok(NULL, " \n\t");
	while (op[i].opcode && op_parsed)
	{
		if (strcmp(op_parsed, op[i].opcode) == 0)
		{	op[i].f(stk_que, line_n);
			return (0);
		}
		i++;
	}
	if (op_parsed && op[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_n, op_parsed);
		fclose(fopcode);
		free(line);
		free_list(*stk_que);
		exit(EXIT_FAILURE); }
	return (1);
}
