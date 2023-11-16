#include "monty.h"
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: nothing
 */
int main(int argc, char *argv[])
{
	stack_t *stack;
	unsigned int line_num = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stack = NULL;
	file_process(argv[1], &stack, &line_num);
	free_stack(stack);
	return (0);
}
