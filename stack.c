#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * free_stack - frees a stack_t stack.
 * @stack: pointer to the top or
 *         bottom of a stack_t.
 */
void free_stack(stack_t **stack)

{
	stack_t *t = *stack;

	while (*stack)
	{
		t = (*stack)->next;
		free(*stack);
		*stack = t;
	}
}

/**
 * init_stack - a function that initializes a stack_t stack
 * with starting stack and ending queue nodes.
 * @stack: pointer to stack_t stack to initialize
 *
 * Return: EXIT_FAILURE (error)
 *         Otherwise - EXIT_SUCCESS.
 */
int init_stack(stack_t **stack)

{
	stack_t *stk;

	stk = malloc(sizeof(stack_t));
	if (stk == NULL)
		return (malloc_error());

	stk->n = STACK;
	stk->prev = NULL;
	stk->next = NULL;

	*stack = stk;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - Checks if a list is in stack or queue mode.
 * @stack: Pointer to the stack or queue of a list
 *
 * Return: If in stack mode - STACK (0).
 *         If in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int check_mode(stack_t *stack)

{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
