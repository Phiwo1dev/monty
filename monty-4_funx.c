#include "monty.h"

void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);

/**
 * monty_rotl - Rotates the top value to the bottom of the list
 * @stack: top node of a stack_t linked list.
 * @line_number: current line
 */
void monty_rotl(stack_t **stack, unsigned int line_number)

{
	stack_t *up, *down;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	up = (*stack)->next;
	down = (*stack)->next;
	while (down->next != NULL)
		down = down->next;

	up->next->prev = *stack;
	(*stack)->next = up->next;
	down->next = up;
	up->next = NULL;
	up->prev = down;

	(void)line_number;
}

/**
 * monty_rotr - Rotates the bottom val of the list to the top.
 * @stack: the top mode node of a linked list.
 * @line_number: current line number
 */
void monty_rotr(stack_t **stack, unsigned int line_number)

{
	stack_t *up, *down;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	up = (*stack)->next;
	down = (*stack)->next;
	while (down->next != NULL)
		down = down->next;

	down->prev->next = NULL;
	(*stack)->next = down;
	down->prev = *stack;
	down->next = up;
	up->prev = down;

	(void)line_number;
}

/**
 * monty_stack - turns a queue into a stack.
 * @stack: pointer to a node at the top of a list
 * @line_number: number of current line
 */
void monty_stack(stack_t **stack, unsigned int line_number)

{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - changes a stack to a queue.
 * @stack: pointer to node of a stack_t linked list.
 * @line_number: current line number
 */
void monty_queue(stack_t **stack, unsigned int line_number)

{
	(*stack)->n = QUEUE;
	(void)line_number;
}
