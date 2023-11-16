#include "monty.h"

/**
 * sub - subtract top element of stack from the second top element of the stack
 * @stack: a pointer to node
 * @line_num: argument
 * Return: result
 */
int sub(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	unsigned int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	if (temp == NULL)
	{
		exit(EXIT_FAILURE);
	}

	result = temp->n - (*stack)->n;
	(*stack)->n = result;
	(*stack)->next = temp->next;

	free(temp);
	return (result);
}
