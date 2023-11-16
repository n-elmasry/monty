#include "monty.h"
/**
* pall - prints all the values on the stack, starting from the top
* @stack: a pointer to node
* @line_num: argument
* Return: nothing
*/
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_num)
{
	stack_t *temp;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%i\n", temp->n);
		temp = temp->next;
	}
}
