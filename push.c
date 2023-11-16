#include "monty.h"
/**
* push - pushes an element to the stack.
* @stack: a pointer to node
* @line_number: argument
*/
void push(stack_t **stack, unsigned int line_number)
{
int value, i;
stack_t *new_node;
char *argument = strtok(NULL, " \t\n");

if (argument == NULL)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE); }

for (i = 0; argument[i] != '\0'; i++)
{
if (!isdigit(argument[i]) && (i == 0 && strchr("+-#", argument[i]) == NULL))

{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE); }}

value = atoi(argument);

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE); }

new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;

if (*stack != NULL)
{
(*stack)->prev = new_node; }
	*stack = new_node; }
