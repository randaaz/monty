#include "monty.h"

/**
 * rl_me - Rotates the stack to the bottom.
 * @sta: A double pointer to the top of the stack.
 * @a: Unused parameter.
 */
void rl_me(stack_t **sta, __attribute__((unused))unsigned int a)
{
	stack_t *tm;

	if (sta == NULL || *sta == NULL || (*sta)->next == NULL)
		return;

	tm = *sta;
	while (tm->next != NULL)
		tm = tm->next;

	tm->next = *sta;
	(*sta)->prev = tm;
	*sta = (*sta)->next;
	(*sta)->prev->next = NULL;
	(*sta)->prev = NULL;
}

/**
 * print_t - Prints the top element of a stack_t list.
 * @s: Pointer to the stack_t list.
 * @ln: Line number.
 */
void print_t(stack_t **s, unsigned int ln)
{
	if (s == NULL || *s == NULL)
		_error1(6, ln);
	printf("%d\n", (*s)->n);
}

/**
 * _error - handles general errors.
 * @err: The error code.
 * @...: Additional arguments depending on the error code.
 */
void _error(int err, ...)
{
	va_list args;
	char *o;
	int len_n;

	va_start(args, err);
	switch (err)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(args, char *));
			break;
		case 3:
			len_n = va_arg(args, int);
			o = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", len_n, o);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	free_n();
	exit(EXIT_FAILURE);
}

/**
 * p_str_me - Prints a string of characters from the stack.
 * @sta: A double pointer to the top of the stack.
 * @a: Unused parameter.
 */
void p_str_me(stack_t **sta, __attribute__((unused))unsigned int a)
{
	int ac;
	stack_t *tm;

	if (sta == NULL || *sta == NULL)
	{
		printf("\n");
		return;
	}

	tm = *sta;
	while (tm != NULL)
	{
		ac = tm->n;
		if (ac <= 0 || ac > 127)
			break;
		printf("%c", ac);
		tm = tm->next;
	}
	printf("\n");
}


/**
 * _nodes4 - Divides the second and top elements of the stack.
 * @sta: A double pointer to the top of the stack.
 * @l_n: The line number for error handling.
 */
void _nodes4(stack_t **sta, unsigned int l_n)
{
	int add;

	if (sta == NULL || *sta == NULL || (*sta)->next == NULL)
		_error1(8, l_n, "div");

	if ((*sta)->n == 0)
		_error1(9, l_n);
	(*sta) = (*sta)->next;
	add = (*sta)->n / (*sta)->prev->n;
	(*sta)->n = add;
	free((*sta)->prev);
	(*sta)->prev = NULL;
}
