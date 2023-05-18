#include "shell.h"

/**
 * char_finder - checks if a character is on array.
 *
 * @c: Character to be checked.
 * @array: String of charaters to be compated.
 *
 * Return: True if it is on it, else false.
*/

bool char_finder(char c, char *array)
{
	int s;

	for (s = 0; array[s]; s++)
	{
		if (c == array[s])
			return (true);
	}
	return (false);
}

/**
 * words_count - counts the number of words in a string specified by
 * one or more seprator. It also counts the length of
 * each word and stores them in an array.
 *
 * @str: String to be parsed.
 * @separators: One or more delimiters to separate the string by.
 * @p_array: Pointer to array where the word lengths will be stored.
 *
 * Return: Number of words.
*/

int words_count(char *str, char *separators, unsigned int *p_array)
{
	unsigned int copy_index, sep_index, length = 1;
	unsigned int counter = 0;
	char *copier = str;
	bool start = false, is_separator;

	if (!str)
		return (0);
	while (!start)
		for (sep_index = 0; separators[sep_index]; sep_index++)
		{
			if (*copier == separators[sep_index])
				copier++;
			else
				start = true;
		}
	if (!*(copier + 1))
	{
		p_array[0] = 1;
		return (1);
	}
	for (copy_index = 1; copier[copy_index]; copy_index++)
	{
		is_separator = char_finder(copier[copy_index], separators);

		if (is_separator && !(char_finder(copier[copy_index - 1], separators)))
		{
			p_array[counter] = length;
			counter++;
		}
		if ((!copier[copy_index + 1]) && !is_separator)
		{
			length++;
			p_array[counter] = length;
			counter++;
			break;
		}
		length = (is_separator) ? 0 : (length + 1);
	}
	return (counter);
}

/**
 * split_string - counts the number of words in a string specified by
 * one or more delimiter. It also counts the length of
 * each word and stores them in an array.
 *
 * @str: String to be parsed.
 * @separators: One or more delimiters to separate the string by.
 * @word_count: Pointer to array where the word lengths will be stored.
 *
 * Return: Number of words.
*/

char **split_string(char *str, char *separators, size_t *word_count)
{
	int split_index, words_len;
	char **words;
	char *copier = str;
	unsigned int c, word_sizes[100];

	init_int_array(word_sizes, 100);
	words_len = words_count(str, separators, word_sizes);

	if (words_len == 0)
		return (NULL);
	words = malloc((sizeof(char *) * words_len) + 1);
	if (!words)
		return (NULL);
	for (split_index = 0; split_index < words_len; split_index++)
	{
		words[split_index] = malloc((sizeof(char) * word_sizes[split_index]) + 1);
	if (!words[split_index])
	{
	for (split_index--; split_index >= 0; split_index--)
		free(words[split_index]);
	free(words);
	return (NULL);
	}
	for (c = 0; c < word_sizes[split_index]; c++, copier++)
	{
		while (char_finder(*copier, separators))
			copier++;

		words[split_index][c] = *copier;
	};
	words[split_index][c] = '\0';
	}
	*word_count = words_len;
	words[split_index] = NULL;

	return (words);
}
