#include "monty.h"

int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);

/**
 * usage_error -prints error messages for usage
 *
 * Return: EXIT_FAILURE
 */
int usage_error(void)

{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - prints malloc error messages.
 *
 * Return: EXIT_FAILURE
 */
int malloc_error(void)

{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - prints file openning error messages
 * @filename: name of the file that failed to open
 *
 * Return: EXIT_FAILURE
 */
int f_open_error(char *filename)

{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - prints error messages for unknown instructions.
 * @opcode: Opcode where the error is
 * @line_number: line where error occured.
 *
 * Return: EXIT_FAILURE
 */
int unknown_op_error(char *opcode, unsigned int line_number)

{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - prints error messages.
 * @line_number: line number where error is located
 *
 * Return: EXIT_FAILURE
 */

int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
