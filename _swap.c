#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: a pointer to node
 * @line_num: argument
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *temp1, *temp2;
	unsigned int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp1 = *stack;
	temp2 = (*stack)->next;

	temp = temp1->n;
	temp1->n = temp2->n;
	temp2->n = temp;
	if (temp1->next != NULL)
	{
		temp1->next->prev = temp1;
	}

}
