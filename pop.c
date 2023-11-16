#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: a pointer to node
 * @line_num: argument
 */
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL)
	{
		fprintf(stderr, "L%u: can't pop, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(temp);

}
