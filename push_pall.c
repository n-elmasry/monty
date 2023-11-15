#include "monty.h"
/*pall*/
void pall(stack_t **stack, unsigned int line_num)
{
    stack_t *temp = *stack;
    UNUSED(line_num);
    while (temp != NULL)
    {
        printf("%i\n", temp->n);
        temp = temp->next;
    }
}

/*push*/

void push(stack_t **stack, unsigned int line_num)
{
int value;
stack_t *new_node;
char *argument = strtok(NULL, " \t\n");

if (argument == NULL)
{
fprintf(stderr, "L%u: usage: push integer\n", line_num);
exit(EXIT_FAILURE);
}


if (!isdigit(*argument) && *argument != '-' && *argument != '+')
{
fprintf(stderr, "L%u: usage: push integer\n", line_num);
exit(EXIT_FAILURE);
}

value = atoi(argument);

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;

if (*stack != NULL)
{
(*stack)->prev = new_node;
}
*stack = new_node;
}
