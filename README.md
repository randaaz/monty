# Monty - Bytecode Interpreter

## Overview
This project involves the implementation of a Monty Bytecode Interpreter in C, focusing on the concepts of stacks and queues, and understanding the LIFO (Last In, First Out) and FIFO (First In, First Out) principles.

### Team Members
- Rasha Saeed
- Randa Saeed

## Learning Objectives
By the end of this project, participants are expected to understand and explain the following concepts without external assistance:
- LIFO and FIFO principles
- Stack and queue structures and their use cases
- Common implementations of stacks and queues
- Common use cases for stacks and queues
- Proper usage of global variables in C

## Requirements
### General
- Allowed Editors: vi, vim, emacs
- Compilation on Ubuntu 20.04 LTS using gcc with specific options
- Files end with a new line
- Mandatory README.md file at the root of the project folder
- Code should follow the Betty style (checked using betty-style.pl and betty-doc.pl)
- Maximum one global variable allowed
- No more than 5 functions per file
- Usage of C standard library
- Prototypes of all functions in the header file "monty.h"
- Include guards for header files
- Tasks to be completed in the specified order
- One project repository per group on GitHub

### Data Structures
Participants are required to use the following data structures, which should be included in the header file:
```c
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

### Task 0: push, pall
**Objective:** Implement the push and pall opcodes.

### The `push` Opcode:
- **Usage:** `push <int>`
- **Description:** The `push` opcode pushes an element onto the stack.
- **Error Handling:**
  - If `<int>` is not an integer or if no argument is given, print the error message `L<line_number>: usage: push integer` and exit with status `EXIT_FAILURE`.
  - `<line_number>` represents the line number in the file.
- **Note:** Overflow conditions do not need to be handled. Use the `atoi` function.

### The `pall` Opcode:
- **Usage:** `pall`
- **Description:** The `pall` opcode prints all the values on the stack, starting from the top.
- **Format:** See the example.
- **Note:** If the stack is empty, don't print anything.

#### Example:
```bash
julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/monty$

### Task 1: pint
**Objective:** Implement the pint opcode.

### The `pint` Opcode:
- **Usage:** `pint`
- **Description:** The `pint` opcode prints the value at the top of the stack, followed by a new line.
- **Error Handling:**
  - If the stack is empty, print the error message `L<line_number>: can't pint, stack empty` and exit with status `EXIT_FAILURE`.

#### Example:
```bash
julien@ubuntu:~/monty$ cat bytecodes/06.m
push 1
pint
push 2
pint
push 3
pint
julien@ubuntu:~/monty$ ./monty bytecodes/06.m
1
2
3
julien@ubuntu:~/monty$

## Task 2: pop
**Objective:** Implement the pop opcode.

### The `pop` Opcode:
- **Usage:** `pop`
- **Description:** The `pop` opcode removes the top element of the stack.
- **Error Handling:**
  - If the stack is empty, print the error message `L<line_number>: can't pop an empty stack` and exit with status `EXIT_FAILURE`.

#### Example:
```bash
julien@ubuntu:~/monty$ cat bytecodes/07.m
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
julien@ubuntu:~/monty$ ./monty bytecodes/07.m
3
2
1
2
1
1
julien@ubuntu:~/monty$

### Task 3: swap
**Objective:** Implement the swap opcode.

### The `swap` Opcode:
- **Usage:** `swap`
- **Description:** The `swap` opcode swaps the top two elements of the stack.
- **Error Handling:**
  - If the stack contains less than two elements, print the error message `L<line_number>: can't swap, stack too short` and exit with status `EXIT_FAILURE`.

#### Example:
```bash
julien@ubuntu:~/monty$ cat bytecodes/09.m
push 1
push 2
push 3
pall
swap
pall
julien@ubuntu:~/monty$ ./monty bytecodes/09.m
3
2
1
2
3
1
julien@ubuntu:~/monty$

## Task 4: add
**Objective:** Implement the add opcode.

### The `add` Opcode:
- **Usage:** `add`
- **Description:** The `add` opcode adds the top two elements of the stack.
- **Error Handling:**
  - If the stack contains less than two elements, print the error message `L<line_number>: can't add, stack too short` and exit with status `EXIT_FAILURE`.
- The result is stored in the second top element of the stack, and the top element is removed.

#### Example:
```bash
julien@ubuntu:~/monty$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall
julien@ubuntu:~/monty$ ./monty bytecodes/12.m 
3
2
1
5
1
julien@ubuntu:~/monty$

## Task 5: nop
**Objective:** Implement the nop opcode.

### The `nop` Opcode:
- **Usage:** `nop`
- **Description:** The `nop` opcode does nothing.

## GitHub Repository
- **GitHub Repository Link:** [monty](https://github.com/your-username/monty)

### advanced tasks
14 advanced tasks
