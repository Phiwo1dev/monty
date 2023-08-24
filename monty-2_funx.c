#include "monty.h"

void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

/**
 * monty_add - adds the 2 top values of a stack_t linked list.
 * @stack: pointer to the top node
 * @line_number: line number of a monty bytecodes file.
 *
 */
void monty_add(stack_t **stack, unsigned int line_number)

{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_sub - takes away the 2nd value from the top of the list
 * @stack: pointer to a node at the top of linked list.
 * @line_number: number of the current line
 *
 * Description: Result is saved into the 2nd value node
 *              from the top, & the top value is removed.
 */
void monty_sub(stack_t **stack, unsigned int line_number)

{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_div - Divides the 2nd val from the top of
 *             a stack_t linked list by the value on top.
 * @stack: pointer to the top mode node of the list.
 * @line_number: The current line of the file.
 *
 * Description: The result is stored in the 2nd node"s val
 *              from the top, the top val is removed.
 */
void monty_div(stack_t **stack, unsigned int line_number)

{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mul - Multiplies the 2nd value from the top of the list
 *             by val at the top
 * @stack: top mode node of a stack_t linked list.
 * @line_number: current line number of a monty bytecodes file.
 *
 */
void monty_mul(stack_t **stack, unsigned int line_number)

{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mod - gives the modulus of the 2nd value from the
 *             top of a the list by the top value.
 * @stack: top mode node of a stack_t linked list.
 * @line_number: line number of a monty bytecodes file
 */
void monty_mod(stack_t **stack, unsigned int line_number)

{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}
