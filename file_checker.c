#include "shell.h"

/**
 * _file_status - check if find found in give path.
 *
 * @pathname: full file path name.
 * @statbuf: status of file.
 *
 * Return: true if file found else false.
 */

bool _file_status(char *pathname, struct stat *statbuf)
{
	int stat_return;

	stat_return = stat(pathname, statbuf);

	if (stat_return == 0)
		return (true);

	return (false);
}

/**
 * _file_path - search for file name in path env
 *		and return first one path's.
 *
 * @filename: file name to search for.
 * @statbuf: status of file.
 *
 * Return: file path if found eles null.
 */

char *_file_path(char *filename, struct stat *statbuf)
{
	size_t s, paths_count;
	char *full_path;
	char *current_path = _getenv("PATH");
	char **paths = split_string(current_path, ":", &paths_count);

	for (s = 0; s < paths_count; s++)
	{
		full_path = _concat(3, paths[s], "/", filename);
		if (_file_status(full_path, statbuf))
		{
			free_string_array(paths, paths_count);
			return (full_path);
		}
	}

	free_string_array(paths, paths_count);
	free(full_path);
	return (NULL);
}
