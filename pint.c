/**
 * _pint - prints the value at the top of the stack
 *
 * @head: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _pint(stack_t **head, unsigned int cline)
{
	(void)cline;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.fopcode);
		free(bus.line);
		free_list(*head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
