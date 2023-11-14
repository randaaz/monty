#include "monty.h"

/**
 * _error1 - handles specific errors.
 * @err: The error code.
 * @...: Additional arguments depending on the error code.
 */

void _error1(int err, ...)
{
	va_list args;
	char *o;
	int len_n;

	va_start(args, err);
	switch (err)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
					va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
					va_arg(args, int));
			break;
		case 8:
			len_n = va_arg(args, unsigned int);
			o = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", len_n, o);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
					va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	free_n();
	exit(EXIT_FAILURE);
}

/**
 * m_nd_me - Multiplies the second and top elements of the stack.
 * @sta: A double pointer to the top of the stack.
 * @l_n: The line number for error handling.
 */
void m_nd_me(stack_t **sta, unsigned int l_n)
{
	int add;

	if (sta == NULL || *sta == NULL || (*sta)->next == NULL)
		_error1(8, l_n, "mul");

	(*sta) = (*sta)->next;
	add = (*sta)->n * (*sta)->prev->n;
	(*sta)->n = add;
	free((*sta)->prev);
	(*sta)->prev = NULL;
}


/**
 * pt - Removes the top element of a stack_t list.
 * @s: Pointer to the stack_t list.
 * @ln: Line number.
 */

void pt(stack_t **s, unsigned int ln)
{
	stack_t *tm;

	if (s == NULL || *s == NULL)
		_error1(7, ln);

	tm = *s;
	*s = tm->next;
	if (*s != NULL)
		(*s)->prev = NULL;
	free(tm);
}


/**
 * _nodes1 - Swaps the top two elements of the stack.
 * @sta: A double pointer to the top of the stack.
 * @l_n: The line number for error handling.
 */
void _nodes1(stack_t **sta, unsigned int l_n)
{
	stack_t *tm;

	if (sta == NULL || *sta == NULL || (*sta)->next == NULL)
		_error1(8, l_n, "swap");
	tm = (*sta)->next;
	(*sta)->next = tm->next;
	if (tm->next != NULL)
		tm->next->prev = *sta;
	tm->next = *sta;
	(*sta)->prev = tm;
	tm->prev = NULL;
	*sta = tm;
}

/**
 * md_nd_me - Computes the modulo of the second and top elements of the stack.
 * @sta: A double pointer to the top of the stack.
 * @l_n: The line number for error handling.
 */
void md_nd_me(stack_t **sta, unsigned int l_n)
{
	int add;

	if (sta == NULL || *sta == NULL || (*sta)->next == NULL)

		_error1(8, l_n, "mod");


	if ((*sta)->n == 0)
		_error1(9, l_n);
	(*sta) = (*sta)->next;
	add = (*sta)->n % (*sta)->prev->n;
	(*sta)->n = add;
	free((*sta)->prev);
	(*sta)->prev = NULL;
}
