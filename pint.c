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

	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		print("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (n_node != NULL)
	{
		printf("%d\n", n_node->n);
	}
}
