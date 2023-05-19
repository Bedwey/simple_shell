#include "shell.h"

/**
 * _file_finder - search for file.
 *
 * @args: user input arguments.
 * @statbuf: stat of file.
 * @args_count: count of args.
 *
 * Return: true if found file else false.
*/

bool _file_finder(char *args[], struct stat statbuf, int args_count)
{
	char *fullpath = NULL;

	if (!_file_status(args[0], &statbuf))
	{
		fullpath = _file_path(args[0], &statbuf);
		if (!fullpath)
		{
			perror("Error (_file_path)");
			free_string_array(args, args_count);
			return (false);
		}
		else
		{
			free(args[0]);
			args[0] = fullpath;
		}
	}

	return (true);
}


/**
 * _execute - Executes a command in a child process.
 *
 * @args: buffer pointer.
 * @envp: An array of user enviroment.
 *
 * Return: error code if there is one.
 *      else The exit value of the last executed command.
*/

int _execute(char *args[], char *envp[])
{
	pid_t wpid;
	int status;

	wpid = fork();
	if (wpid == -1)
	{
		perror("Error > pid");
		exit(EXIT_FAILURE);
	}

	if (wpid == 0)
	{
		return (execve(args[0], args, envp));
	}
	else
	{
		waitpid(wpid, &status, 0);
	}
	return (status);
}

/**
 * main - Entry point to shell program
 *
 * @argc: Number of arguments passed into the shell executable.
 * @argv: Vector containing arguments passed.
 * @envp:  An array of user enviroment.
 *
 * Return: 0 on success or 1 on failure.
*/

int main(__attribute__((unused)) int argc, char *argv[], char **envp)
{
	char *buff = NULL, *prompt = "$ ";
	char **args;
	size_t bytes;
	size_t args_count, buff_size = 0;
	struct stat statbuf;
	bool from_user = false;
	char *app_name = argv[0];

	while (true && !from_user)
	{
		from_user = !isatty(STDIN_FILENO);
		if (!from_user)
			write(STDOUT_FILENO, prompt, 2);
		bytes = getline(&buff, &buff_size, stdin);
		if ((int)bytes == -1)
		{
			perror(app_name);
			free(buff);
			exit(EXIT_FAILURE);
		}
		if (buff[bytes - 1] == '\n')
			buff[bytes - 1] = '\0';
		args = split_string(buff, " ", &args_count);
		if (handle_builtin(args, args_count))
			continue;
		if (!_file_finder(args, statbuf, args_count))
			continue;

		if (_execute(args, envp) == -1)
			perror(app_name);
		free_string_array(args, args_count);
	}

	free(buff);
	return (0);
}
