#include "monty.h"

/**
 *add_dnodeint_end - add a note at the end of the doubly link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a doubly linked list
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *temp, *aux;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		printf("Error\n");
		exit(0);
	}
	temp->n = n;
	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	temp->next = aux->next;
	temp->prev = aux;
	aux->next = temp;
	return (aux->next);
}

/**
 *add_dnodeint - add a note at the begining of the doubly link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a doubly linked list
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		printf("Error\n");
		exit(0);
	}
	temp->n = n;
	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;
	return (*head);
}
#include "monty.h"
/**
 * free_stack - frees the stack
 * @h: the stack to be freed
 * Return: Nothing.
 */
void free_stack(stack_t **h)
{
	while (*h != NULL)
	{
		stack_t *temp;

		temp = *h;
		*h = (*h)->next;
		free(temp);
	}
}
