#include "monty.h"

/**
 * print_s - Prints all the elements of a stack_t list.
 * @s: Pointer to the stack_t list.
 * @ln: Line number (unused).
 */

void print_s(stack_t **s, unsigned int ln)
{
	stack_t *tm;

	(void) ln;
	if (s == NULL)
		exit(EXIT_FAILURE);
	tm = *s;
	while (tm != NULL)
	{
		printf("%d\n", tm->n);
		tm = tm->next;
	}
}

/**
 * f_function - Matches Monty script instructions to corresponding functions.
 * @oc: Operation code representing a Monty instruction.
 * @v: Value associated with the instruction (if any).
 * @a: Line number of the script.
 * @shape: Stack or queue indicator.
 */
void f_function(char *oc, char *v, int a, int shape)
{
	int j;
	int fl;

	instruction_t func_list[] = {
		{"push", _stack_me},
		{"pall", print_s},
		{"pint", print_t},
		{"pop", pt},
		{"nop", m},
		{"swap", _nodes1},
		{"add", _nodes2},
		{"sub", _nodes3},
		{"div", _nodes4},
		{"mul", m_nd_me},
		{"mod", md_nd_me},
		{"pchar", p_char},
		{"pstr",  p_str_me},
		{"rotl", rl_me},
		{"rotr", rt_me},
		{NULL, NULL}
	};

	if (oc[0] == '#')
		return;

	for (fl = 1, j = 0; func_list[j].opcode != NULL; j++)
	{
		if (strcmp(oc, func_list[j].opcode) == 0)
		{
			c_function(func_list[j].f, oc, v, a, shape);
			fl = 0;
		}
	}
	if (fl == 1)
		_error(3, a, oc);
}

/**
 * p_char - Prints the character value at the top of the stack.
 * @sta: A double pointer to the top of the stack.
 * @l_n: The line number for error handling.
 */
void p_char(stack_t **sta, unsigned int l_n)
{
	int ac;

	if (sta == NULL || *sta == NULL)
		_error2(11, l_n);

	ac = (*sta)->n;
	if (ac < 0 || ac > 127)
		_error2(10, l_n);
	printf("%c\n", ac);
}

/**
 * m - Placeholder function.
 * @sta: A double pointer to the top of the stack.
 * @l_n: The line number for error handling.
 */
void m(stack_t **sta, unsigned int l_n)
{
	(void)sta;
	(void)l_n;
}

/**
 * _error2 - handles string-related errors.
 * @err: The error code.
 * @...: Additional arguments depending on the error code.
 */

void _error2(int err, ...)
{
	va_list args;
	int len_n;

	va_start(args, err);
	len_n = va_arg(args, int);
	switch (err)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", len_n);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", len_n);
			break;
		default:
			break;
	}
	free_n();
	exit(EXIT_FAILURE);
}
