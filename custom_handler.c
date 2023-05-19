#include "shell.h"

/**
 * handle_exit - handle exit function.
 *
 * @exit_args: exit arguments.
 * @count: count of args.
 *
 * Return: nothing.
*/

void handle_exit(char **exit_args, size_t count)
{
	int status = EXIT_SUCCESS;

	if (exit_args[1])
		status = _atoi(exit_args[1]);

	free_string_array(exit_args, count);
	exit(status);
}
