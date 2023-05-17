#include "shell.h"

/**
 * _execute - Executes a command in a child process.
 *
 * @buff: buffer pointer.
 * @argv: An array of arguments.
 * @env: An array of user enviroment.
 *
 * Return: error code if there is one.
 *	else The exit value of the last executed command.
 */

int _execute(char *buff, char *argv[], char *env[])
{
	pid_t wpid;
	int status;

	wpid = fork();
	if (wpid == -1)
	{
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}

	if (wpid == 0)
	{
		return (execve(buff, argv, env));
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
 * @env:  An array of user enviroment.
 *
 * Return: 0 on success or 1 on failure.
 */

int main(__attribute__((unused)) int argc, char *argv[], char **env)
{
	char *prompt = "$ ";
	char *buff = NULL;
	size_t buff_size = 0;
	size_t bytes;
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

		if (_execute(buff, argv, env) == -1)
			perror(app_name);
	}

	free(buff);
	return (0);
}
