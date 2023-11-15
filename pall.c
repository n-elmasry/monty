#include "monty.h"
/*pall*/
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	temp = *stack;
	UNUSED(line_num);
	while (temp != NULL)
	{
		printf("%i\n", temp->n);
		temp = temp->next;
	}
}
