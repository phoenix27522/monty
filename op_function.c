#include "monty.h"
/**
 * op_push - process the push opcode
 * @h: double pointer to the top of the stack
 * @line_n: current line number
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
 * op_pall - handles the pall in monty code
 * @h: pointer to pointer to the stack
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
/**
 * op_pint - prints the value at the top of the stack.
 * @h: pointer to pointer to the stack
 * @line_n: the line number
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
/**
 * op_pop - removes the top element of the stack.
 * @h: pointer to pointer to the stack
 * @line_n: the line number
 * Return: Nothing
 */
void op_pop(stack_t **h, unsigned int line_n)
{
	stack_t *temp;

	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_n);
		exit(EXIT_FAILURE);
	}

	temp = *h;
	*h = (*h)->next;
	free(temp);
}
/**
 * op_swap - handles the pall in monty code
 * @h: pointer to pointer to the stack
 * @line_n: the line number
 * Return: Nothing
 */
void op_swap(stack_t **h, unsigned int line_n)
{
	int n = 0;
	stack_t *temp = NULL;

	temp = *h;

	for (; temp != NULL; temp = temp->next, n++)
		;

	if (n < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}

	temp = *h;
	*h = (*h)->next;
	temp->next = (*h)->next;
	temp->prev = *h;
	(*h)->next = temp;
	(*h)->prev = NULL;
}

