#include "monty.h"

int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);

/**
 * pop_error - prints pop error messages for empty stacks.
 * @line_number: Line in script containing the error
 *
 * Return: EXIT_FAILURE
 */
int pop_error(unsigned int line_number)

{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - print error messages for empty stacks.
 * @line_number: Line in Monty bytecodes file where error happened
 *
 * Return: EXIT_FAILURE
 */
int pint_error(unsigned int line_number)

{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - prints error messages for math function
 *                     for stacks/queues smaller than two nodes.
 * @line_number: Line number where error happened
 * @op: Op where the error happened
 *
 * Return: EXIT_FAILURE
 */
int short_stack_error(unsigned int line_number, char *op)

{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - prints division error messages for division by 0.
 * @line_number: Line where error was detected
 *
 * Return: EXIT_FAILURE
 */
int div_error(unsigned int line_number)

{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - prints pchar error messages for empty stacks
 *               and non-char values.
 * @line_number: line where the error occurred.
 * @message: error message tobe printed
 *
 * Return: EXIT_FAILURE
 */
int pchar_error(unsigned int line_number, char *message)

{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
