#include "monty.h"

/**
 * _nodes2 - Adds the top two elements of the stack.
 * @sta: A double pointer to the top of the stack.
 * @l_n: The line number for error handling.
 */
void _nodes2(stack_t **sta, unsigned int l_n)
{
	int add;

	if (sta == NULL || *sta == NULL || (*sta)->next == NULL)
		_error1(8, l_n, "add");

	(*sta) = (*sta)->next;
	add = (*sta)->n + (*sta)->prev->n;
	(*sta)->n = add;
	free((*sta)->prev);
	(*sta)->prev = NULL;
}

/**
 * Separates_l - Separates a line into tokens and processes the first token.
 * @b: The line to process.
 * @ln: Line number.
 * @shape: Data structure type (0 for stack, 1 for queue).
 * Return: Updated shape.
 */


int Separates_l(char *b, int ln, int shape)
{
	char *oc, *v;
	const char *del = "\n ";

	if (b == NULL)
		_error(4);

	oc = strtok(b, del);
	if (oc == NULL)
		return (shape);
	v = strtok(NULL, del);

	if (strcmp(oc, "stack") == 0)
		return (0);
	if (strcmp(oc, "queue") == 0)
		return (1);

	f_function(oc, v, ln, shape);
	return (shape);
}

/**
 * r_f - Reads the content of a file.
 * @file_Descriptor: File descriptor of the open file.
 */

void r_f(FILE *file_Descriptor)
{
	int ln, shape = 0;
	char *b = NULL;
	size_t l = 0;

	for (ln = 1; getline(&b, &l, file_Descriptor) != -1; ln++)
	{
		shape = Separates_l(b, ln, shape);
	}
	free(b);
}
