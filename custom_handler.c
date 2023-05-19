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

/**
 * handle_env - prints the current environment.
 *
 * @env_args: user input args.
 * @count: count of args to free array.
 *
 * Return: nothing.
*/

void handle_env(char **env_args, size_t count)
{
	if (env_args[1] == NULL)
	{
		int index;

		for (index = 0; environ[index]; index++)
			_puts(environ[index]);
	}

	free_string_array(env_args, count);
}

/**
 * handle_builtin - handle builtin function.
 *
 * @args: user input arguments.
 * @count: count of args.
 *
 * Return: true if handled else false.
*/

bool handle_builtin(char **args, size_t count)
{
	if (_strncmp(args[0], "exit", 4) == 0)
		handle_exit(args, count);
	else if (_strncmp(args[0], "env", 3) == 0)
	{
		handle_env(args, count);
		return (true);
	}

	return (false);
}

