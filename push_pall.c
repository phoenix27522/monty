#include "monty.h"
/**
 * op_pall - print the list
 *
 * @h: a pointer to the struct
 * @line_n: line number
 * Return: all the value of the list
 *
 */
void op_pall(stack_t **h, unsigned int line_n)
{
	(void) line_n;

	while (*h)
	{
		printf("%d\n", (*h)->n);
		*h = (*h)->next;
	}
}

#include "monty.h"

/**
 * op_push - pushes an element to the stack
 *
 * @h: head of the linked list
 * @line_n: line number
 * Return: no return
 */
void op_push(stack_t **h, unsigned int line_n)
{
	int n, j;

	if (!global.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_n);
		fclose(global.fopcode);
		free(global.line);
		free_list(*h);
		exit(EXIT_FAILURE);
	}

	for (j = 0; global.arg[j] != '\0'; j++)
	{
		if (!isdigit(global.arg[j]) && global.arg[j] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_n);
			fclose(global.fopcode);
			free(global.line);
			free_list(*h);
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(global.arg);

	if (global.lifo == 1)
		add_dnodeint(h, n);
	else
		add_dnodeint_end(h, n);
}
