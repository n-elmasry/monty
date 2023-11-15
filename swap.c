#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: a pointer to node
 * @line_num: argument
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *temp1, *temp2;

	if (*stack == NULL && (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp1 = *stack;
	temp2 = (*stack)->next;

	temp1->prev = NULL;
	temp2 = *stack;
	temp1->prev = temp2;
	temp2->next = temp1;
	temp1->next = (*stack)->next;
	if (temp1->next != NULL)
	{
		temp1->next->prev = temp1;
	}
}
