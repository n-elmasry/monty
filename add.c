#include "monty.h"
/**
* add - adds the top two elements of the stack.
* @stack: a pointer to node
* @line_num: argument
* Return: result
*/
int add(stack_t **stack, unsigned int line_num)
{
stack_t *temp;
int result;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
exit(EXIT_FAILURE);
}

temp = (*stack)->next;

if (temp == NULL)
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
exit(EXIT_FAILURE);
}

result = (*stack)->n + temp->n;

(*stack)->n = result;
(*stack)->next = temp->next;

free(temp);
return (result);
}
