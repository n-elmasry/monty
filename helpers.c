#include "monty.h"
/**
* free_stack - frees stack
* @stack: a pointer to node
* Return: nothing
*/
void free_stack(stack_t *stack)
{
while (stack != NULL)
{
stack_t *temp = stack;
stack = stack->next;
free(temp);
}
}
/**
* opcode_process - opcode process
* @stack: a pointer to node
* @line_num: line numberi
* @opcode: opcode
* Return: nothing
*/
void opcode_process(char *opcode, stack_t **stack, unsigned int line_num)
{
if (strcmp(opcode, "push") == 0)
{
push(stack, line_num);
}
else if (strcmp(opcode, "pall") == 0)
{
pall(stack, line_num);
}
else if (strcmp(opcode, "pint") == 0)
{
pint(stack, line_num);
}
else if (strcmp(opcode, "pop") == 0)
{
pop(stack, line_num);
}
else if (strcmp(opcode, "swap") == 0)
{
swap(stack, line_num);
}
else if (strcmp(opcode, "add") == 0)
{
add(stack, line_num);
}
else if (strcmp(opcode, "nop") == 0)
{
nop(stack, line_num);
}
else
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
exit(EXIT_FAILURE);
}
}

/**
* file_process - file process
* @stack: a pointer to node
* @line_num: line number
* @filename: file name
* Return: nothing
*/
void file_process(char *filename, stack_t **stack, unsigned int *line_num)
{
FILE *fptr;
char line[100];
char *opcode;

fptr = fopen(filename, "r");

if (fptr == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
exit(EXIT_FAILURE);
}

while (fgets(line, sizeof(line), fptr) != NULL)
{
(*line_num)++;
opcode = strtok(line, " \t\n");
if (opcode != NULL)
{
opcode_process(opcode, stack, *line_num);
}
}

fclose(fptr);
}
