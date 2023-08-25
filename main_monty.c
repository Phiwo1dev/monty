#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - Starting point for Monty interpreter
 *
 * @argc: argument count of the program
 * @argv: argument values
 *
 * Return: (EXIT_SUCCESS) for success,(EXIT_FAILURE) for failure
 */
int main(int argc, char **argv)

{
	FILE *script_fd = NULL;
	int exit = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (f_open_error(argv[1]));
	exit = run_monty(script_fd);
	fclose(script_fd);
	return (exit);
}
