#include "monty.h"

void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);

/**
 * monty_push - pushes a val to stack_t linked list.
 * @stack: pointer to top mode node of a stack_t linked list.
 * @line_number: current working line number of a monty bytecodes file.
 */
void monty_push(stack_t **stack, unsigned int line_number)

{
	stack_t *t, *new;
	int a;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}

	for (a = 0; op_toks[1][a]; a++)
	{
		if (op_toks[1][a] == '-' && a == 0)
			continue;
		if (op_toks[1][a] < '0' || op_toks[1][a] > '9')
		{
			set_op_tok_error(no_int_error(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK)
	{
		t = (*stack)->next;
		new->prev = *stack;
		new->next = t;
		if (t)
			t->prev = new;
		(*stack)->next = new;
	}
	else
	{
		t = *stack;
		while (t->next)
			t = t->next;
		new->prev = t;
		new->next = NULL;
		t->next = new;
	}
}

/**
 * monty_pall - prints stack_t linked list values
 * @stack: A pointer to a node
 * @line_number: current working line num
 */
void monty_pall(stack_t **stack, unsigned int line_number)

{

	stack_t *t = (*stack)->next;

	while (t)
	{
		printf("%d\n", t->n);
		t = t->next;
	}
	(void)line_number;
}

/**
 * monty_pint - prints a stack_t linked list value
 * @stack: A pointer to the top mode node
 * @line_number: current line of a monty bytecodes file.
 */
void monty_pint(stack_t **stack, unsigned int line_number)

{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * monty_pop - removes the top element of a list.
 * @stack: Pointer to the top mode node of a list.
 * @line_number: line number of a Monty bytecodes file.
 */
void monty_pop(stack_t **stack, unsigned int line_number)

{
	stack_t *n = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_error(line_number));
		return;
	}

	n = (*stack)->next->next;
	free((*stack)->next);
	if (n)
		n->prev = *stack;
	(*stack)->next = n;
}

/**
 * monty_swap - Swaps the top 2 elements of a stack_t list.
 * @stack: top node of a stack_t linked list.
 * @line_number: current line number of a monty bytecodes file.
 */
void monty_swap(stack_t **stack, unsigned int line_number)

{
	stack_t *t;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "swap"));
		return;
	}

	t = (*stack)->next->next;
	(*stack)->next->next = t->next;
	(*stack)->next->prev = t;
	if (t->next)
		t->next->prev = (*stack)->next;
	t->next = (*stack)->next;
	t->prev = *stack;
	(*stack)->next = t;
}
