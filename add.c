#include "monty.h"

int add(stack_t **stack, unsigned int line_num)
{
stack_t *temp;
int result;

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
    return(result);
}
