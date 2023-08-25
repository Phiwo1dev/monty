#include "monty.h"

/**
 * set_op_tok_error - a function that sets last element
 * of op_toks to an error code.
 * @error_code: int to be stored as a string in op_toks.
 */
void set_op_tok_error(int error_code)

{
	int tok_len = 0, c = 0;
	char *exit_str = NULL;
	char **new_tok = NULL;

	tok_len = token_arr_len();
	new_tok = malloc(sizeof(char *) * (tok_len + 2));
	if (!op_toks)
	{
		malloc_error();
		return;
	}
	while (c < tok_len)
	{
		new_tok[c] = op_tok[c];
		c++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_tok);
		malloc_error();
		return;
	}
	new_tok[c++] = exit_str;
	new_tok[c] = NULL;
	free(op_tok);
	op_tok = new_tok;
}
