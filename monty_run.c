#include "monty.h"
#include <string.h>

void free_tokens(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);

/**
 * free_tokens - frees array of strings for the global op_toks
 */
void free_tokens(void)

{
	size_t t = 0;

	if (op_toks == NULL)
		return;

	for (t = 0; op_toks[t]; t++)
		free(op_toks[t]);

	free(op_toks);
}

/**
 * token_arr_len - a function that gets the length
 * of current op_toks.
 *
 * Return: length (as interger).
 */
unsigned int token_arr_len(void)

{
	unsigned int tok_len = 0;

	while (op_tok[tok_len])
		tok_len++;
	return (tok_len);
}

/**
 * is_empty_line - checks if a line read from getline
 *                 contains only delimiters.
 * @line: pointer to the line to be checked.
 * @delims: string of delimiter chars.
 *
 * Return: -1 if line contains only delimeters
 *         0 if not
 */
int is_empty_line(char *line, char *delims)

{
	int l, k;

	for (l = 0; line[l]; l++)
	{
		for (k = 0; delims[k]; k++)
		{
			if (line[l] == delims[k])
				break;
		}
		if (delims[k] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - matches opcode with its function.
 * @opcode: opcode to match with its corresponding function
 *
 * Return: Pointer to the function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)

{
	instruction_t op_funcs[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"stack", monty_stack},
		{"queue", monty_queue},
		{NULL, NULL}
	};
	int o;

	for (o = 0; op_funcs[o].opcode; o++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[o].f);
	}

	return (NULL);
}

/**
 * run_monty - function for executing  monty bytecodes script.
 * @script_fd: file descriptor
 *
 * Return: EXIT_SUCCESS (success), err code (failure)
 */
int run_monty(FILE *script_fd)

{
	stack_t *stack = NULL;
	char *c = NULL;
	size_t l = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_num = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&c, &l, script_fd) != -1)
	{
		line_num++;
		op_toks = strtow(c, DELIMS);
		if (op_toks == NULL)
		{
			if (is_empty_line(c, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_error());
		}
		else if (op_toks[0][0] == '#')
		{
			free_tokens();
			continue;
		}
		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_op_error(op_toks[0], line_num);
			free_tokens();
			break;
		}
		prev_tok_len = token_arr_len();
		op_func(&stack, line_num);
		if (token_arr_len() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	free_stack(&stack);

	if (c && *c == 0)
	{
		free(c);
		return (malloc_error());
	}

	free(c);
	return (exit_status);
}
