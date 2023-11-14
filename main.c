#include "monty.h"

stack_t *head = NULL;

/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_me(argv[1]);
	free_n();
	return (0);
}


/**
 * _add - Adds a new node at the end of a stack_t list.
 * @new: Pointer to the new node.
 * @a: Unused parameter.
 */

void _add(stack_t **new, __attribute__((unused))unsigned int a)
{
	stack_t *tmp;

	if (new == NULL || *new == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new;
	(*new)->prev = tmp;

}

/**
 * free_n - Frees all nodes in the stack.
 */

void free_n(void)
{
	stack_t *tm;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tm = head;
		head = head->next;
		free(tm);
	}
}


/**
 * cre_n - Creates a new stack_t node.
 * @num: Value to assign to the new node.
 * Return: Pointer to the new node.
 */

stack_t *cre_n(int num)
{
	stack_t *n;

	n = malloc(sizeof(stack_t));
	if (n == NULL)
		_error(4);
	n->next = NULL;
	n->prev = NULL;
	n->n = num;
	return (n);
}
