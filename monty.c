#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *fptr;
	char line[100];
	unsigned int line_num = 0;
	stack_t *stack = NULL;
	char *opcode;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/*Open file*/
	if ((fptr = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Process lines in file*/
	while (fgets(line, sizeof(line), fptr) != NULL)
	{
		line_num++;

		opcode = strtok(line, " \t\n");

		if (opcode != NULL)
		{
		   /*call func*/
			if (strcmp(opcode, "push") == 0)
			{
				push(&stack, line_num);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall(&stack, line_num);
			}
			else if (strcmp(opcode, "pint") == 0)
			{
				pint(&stack, line_num);
			}
			else if (strcmp(opcode, "pop") == 0)
			{
				pop(&stack, line_num);
			}
			else if (strcmp(opcode, "swap") == 0)
			{
				swap(&stack, line_num);
			}
			else if (strcmp(opcode, "add") == 0)
			{
	 		
				add(&stack, line_num);
			}
			else if (strcmp(opcode, "nop") == 0)
                        {
				continue;
                        }

			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
				exit(EXIT_FAILURE);
			}
			}
			}
	fclose(fptr);
	 while (stack != NULL)
	{
		stack_t *temp = stack;
		stack = stack->next;
		free(temp);
	}
	return (0);
}

