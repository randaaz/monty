#include "monty.h"

/**
 * open_me - Opens a file and reads its contents.
 * @fn: File name to open.
 */

void open_me(char *fn)
{
	FILE *file_Descriptor = fopen(fn, "r");

	if (fn == NULL || file_Descriptor == NULL)
		_error(2, fn);

	r_f(file_Descriptor);
	fclose(file_Descriptor);
}

/**
 * _stack_me - Adds a new node at the beginning of a stack_t list.
 * @new: Pointer to the new node.
 * @a: Unused parameter.
 */

void _stack_me(stack_t **new, __attribute__((unused))unsigned int a)
{
	stack_t *tm;

	if (new == NULL || *new == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new;
		return;
	}
	tm = head;
	head = *new;
	head->next = tm;
	tm->prev = head;
}

/**
 * _nodes3 - Subtracts the top two elements of the stack.
 * @sta: A double pointer to the top of the stack.
 * @l_n: The line number for error handling.
 */
void _nodes3(stack_t **sta, unsigned int l_n)
{
	int add;

	if (sta == NULL || *sta == NULL || (*sta)->next == NULL)

		_error1(8, l_n, "sub");


	(*sta) = (*sta)->next;
	add = (*sta)->n - (*sta)->prev->n;
	(*sta)->n = add;
	free((*sta)->prev);
	(*sta)->prev = NULL;
}

/**
 * c_function - Executes the specified operation function.
 * @func: Pointer to the operation function to be executed.
 * @o: Operation string.
 * @v: Value string.
 * @a: Line number.
 * @format: Format indicator.
 */

void c_function(op_func func, char *o, char *v, int a, int format)
{
	stack_t *n;
	int fl;
	int j;

	fl = 1;
	if (strcmp(o, "push") == 0)
	{
		if (v != NULL && v[0] == '-')
		{
			v = v + 1;
			fl = -1;
		}
		if (v == NULL)
			_error(5, a);
		for (j = 0; v[j] != '\0'; j++)
		{
			if (isdigit(v[j]) == 0)
				_error(5, a);
		}
		n = cre_n(atoi(v) * fl);
		if (format == 0)
			func(&n, a);
		if (format == 1)
			_add(&n, a);
	}
	else
		func(&head, a);
}


/**
 * rt_me - Rotates the stack to the top.
 * @sta: A double pointer to the top of the stack.
 * @a: Unused parameter.
 */
void rt_me(stack_t **sta, __attribute__((unused))unsigned int a)
{
	stack_t *tm;

	if (sta == NULL || *sta == NULL || (*sta)->next == NULL)
		return;

	tm = *sta;

	while (tm->next != NULL)
		tm = tm->next;

	tm->next = *sta;
	tm->prev->next = NULL;
	tm->prev = NULL;
	(*sta)->prev = tm;
	(*sta) = tm;
}
