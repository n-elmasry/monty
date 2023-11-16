#include "monty.h"

/**
 * _div - divide second top element of stack by the top element of the stack
 * @stack: a pointer to node
 * @line_num: argument
 * Return: result
 */
int _div(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	unsigned int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	if (temp->next == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	result = temp->n / (*stack)->n;
	(*stack)->n = result;
	(*stack)->next = temp->next;
	free(temp);
	return (result);
}
