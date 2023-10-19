#include "monty.h"
/**
 * process_push - process the push opcode
 * @h: double pointer to the top of the stack
 * @line_number: current line number
 * Return: Nothing
 */
void op_push(stack_t **h, unsigned int line_n)
{
	char *arg = strtok(NULL, " \t\n$");
	unsigned int i;

	if (arg == NULL)
	{
		stack_t *temp;

		temp = *h;
		fprintf(stderr, "L%d: usage: push integer\n", line_n);
		free_stack(&temp);
		exit(EXIT_FAILURE);
	}

	for (i = 0; arg[i] != '\0'; i++)
	{
		if (i == 0 && (arg[i] == '+' || arg[i] == '-'))
			continue;
		if (arg[i] < '0' || arg[i] > '9')
		{
			stack_t *temp;

			temp = *h;
			fprintf(stderr, "L%d: usage: push integer\n", line_n);
			free_stack(&temp);
			exit(EXIT_FAILURE);
		}
	}
	add_dnodeint(h, atoi(arg));
}
/**
 * pall - handles the pall in monty code
 * @stack: pointer to pointer to the stack
 * @line_n: the line number
 * Return: Nothing
 */
void op_pall(stack_t **h, unsigned int line_n)
{
	stack_t *current;
	(void)line_n;

	current = *h;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
#include "monty.h"
/**
 * pint - prints the value at the top of the stack.
 * @stack: pointer to pointer to the stack
 * @line_number: the line number
 * Return: Nothing
 */

void op_pint(stack_t **h, unsigned int line_n)
{
	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}
