#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <ctype.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void _stack_me(stack_t **, unsigned int);
void _add(stack_t **, unsigned int);
void print_t(stack_t **, unsigned int);
void pt(stack_t **, unsigned int);
void m(stack_t **, unsigned int);
void f_function(char *, char *, int, int);
stack_t *cre_n(int num);
void free_n(void);
void m_nd_me(stack_t **, unsigned int);
void md_nd_me(stack_t **, unsigned int);
void print_s(stack_t **, unsigned int);
extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);
void c_function(op_func, char *, char *, int, int);
void p_char(stack_t **, unsigned int);
void _nodes1(stack_t **, unsigned int);
void p_str_me(stack_t **, unsigned int);
void rl_me(stack_t **, unsigned int);
void _nodes4(stack_t **, unsigned int);
void _nodes2(stack_t **, unsigned int);
void _nodes3(stack_t **, unsigned int);
void _error(int err, ...);
void _error1(int err, ...);
void open_me(char *fn);
int Separates_l(char *b, int ln, int shape);
void r_f(FILE *file_Descriptor);
int len_chars(FILE *);
void _error2(int err, ...);
void rt_me(stack_t **, unsigned int);

#endif
