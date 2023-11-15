#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @stack: a pointer to node
 * @line_num: argument
 */
void pint(stack_t **stack, unsigned int line_num)
{
	stack_t *n_node;
	n_node = *stack;

	if (n_node == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", n_node->n);
}
