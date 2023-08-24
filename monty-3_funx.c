#include "monty.h"

void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);

/**
 * monty_nop - Doesnt do anything for the Monty opcode 'nop'.
 * @stack: Pointer to the node at the top of a list.
 * @line_number: current line of a Monty bytecodes file.
 */
void monty_nop(stack_t **stack, unsigned int line_number)

{
	(void)stack;
	(void)line_number;
}

/**
 * monty_pchar - prints the char in the top of a linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: num of current line of a monty bytecodes file.
 */
void monty_pchar(stack_t **stack, unsigned int line_number)

{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(line_number,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * monty_pstr - outputs the string found in a stack_t linked list.
 * @stack: pointer to the top mode node of a stack_t list
 * @line_number: num of the current line
 */
void monty_pstr(stack_t **stack, unsigned int line_number)

{
	stack_t *m = (*stack)->next;

	while (m && m->n != 0 && (m->n > 0 && m->n <= 127))
	{
		printf("%c", m->n);
		m = m->next;
	}

	printf("\n");

	(void)line_number;
}
