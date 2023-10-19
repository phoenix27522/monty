#include "monty.h"
/**
 * op_add - adds the top two elements of the stack.
 * @h: stack head
 * @line_n: line_number
 * Return: no return
*/
void op_add(stack_t **h, unsigned int line_n)
{
	stack_t *temp;
	int len = 0, sum;

	temp = *h;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	temp = *h;
	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	*h = temp->next;
	free(temp);
}
/**
 * op_nop - doesn't do anythinhg
 *
 * @h: head of the linked list
 * @line_n: line number;
 * Return: no return
 */
void op_nop(stack_t **h, unsigned int line_n)
{
	(void)h;
	(void)line_n;
}
