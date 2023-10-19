#include "monty.h"
/**
 * _pint - prints the value at the top of the stack
 *
 * @head: head of the linked list
 * @cline: line number
 * Return: no return
 */
void op_pint(stack_t **h, unsigned int line_n)
{
	(void)line_n;

	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_n);
		fclose(global.fopcode);
		free(global.line);
		free_list(*h);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*h)->n);
}
