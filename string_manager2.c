#include "shell.h"

/**
 * _concat - concat strings.
 *
 * @count: count of inputs.
 *
 * Return: address of char array of concated strings.
 */

char *_concat(int count, ...)
{
	va_list ap;
	size_t len = 0;
	int index;
	char *ret, *dst;

	if (count < 1)
		return (NULL);
	va_start(ap, count);
	for (index = 0; index < count; index++)
	{
		char *s = va_arg(ap, char *);

		len += _strlen(s);
	}

	va_end(ap);

	ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);

	dst = ret;
	va_start(ap, count);
	for (index = 0; index < count; index++)
	{
		const char *src = va_arg(ap, char *);

		while ((*dst++ = *src++))
		{
		}

		dst--;
	}

	va_end(ap);
	return (ret);
}
