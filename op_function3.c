#include "monty.h"
/**
 * mod - computes the rest of the division of the second
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
