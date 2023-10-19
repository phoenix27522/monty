#include "monty.h"
/**
 * op_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @h: pointer to pointer to the stack
 * @line_n: the line number
 * Return: Nothing
 */
void op_mod(stack_t **h, unsigned int line_n)
{
	stack_t *temp;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	temp = *h;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_n);
		exit(EXIT_FAILURE);
	}
	temp->next->n %= temp->n;
	temp->next->prev = NULL;
	*h = temp->next;
	free(temp);
}
/**
 * op_pchar - print the char value of the first element
 *
 * @h: head of the linked list
 * @line_n: line number;
 * Return: no return
 */
void op_pchar(stack_t **h, unsigned int line_n)
{
	if (*h == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	if ((*h)->n < 0 || (*h)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_n);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)(*h)->n);
}

/**
 * op_pstr - prints the string starting at the top of..
 * @h: pointer to pointer to the stack
 * @line_n: the line number
 * Return: Nothing
 */
void op_pstr(stack_t **h, unsigned int line_n)
{
	stack_t *current = *h;

	(void)line_n;

	while (current != NULL && current->n != 0 &&
			current->n > 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
