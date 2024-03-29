#ifndef monty_h
#define monty_h
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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

void pall(stack_t **stack, unsigned int line_num);
void push(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
int add(stack_t **stack, unsigned int line_num);
void nop(stack_t **stack, unsigned int line_num);
void free_stack(stack_t *stack);
void opcode_process(char *opcode, stack_t **stack, unsigned int line_num);
void file_process(char *filename, stack_t **stack, unsigned int *line_num);
int sub(stack_t **stack, unsigned int line_num);
int _div(stack_t **stack, unsigned int line_num);
#endif
