#include "shell.h"

/**
 * _getenv - get enviromint varibles by key.
 *
 * @key: to search for;
 *
 * Return: eniroment char array of eniroment paths.
*/

char *_getenv(char *key)
{
	size_t nameLen = _strlen(key), env_var_len, i;
	char **env = environ, *env_var;

	for (; *env != NULL; ++env)
	{
		env_var = *env;
		env_var_len = _strlen(env_var);
		if (nameLen <= env_var_len)
		{
			for (i = 0; i < nameLen; ++i)
			{
				if (key[i] != env_var[i])
					break;
			}

			if (i == nameLen && env_var[i] == '=')
				return (&env_var[i + 1]);
		}
	}
	return (NULL);
}
