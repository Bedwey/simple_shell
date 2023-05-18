#include "shell.h"

/**
 * init_int_array - sets all the bytes of an integer array to 0
 *
 * @p_array: Array to be initialized.
 * @size: Size of the array.
 *
 * Return: Nothing
*/

void init_int_array(unsigned int *p_array, size_t size)
{
	size_t x;

	for (x = 0; x < size; x++)
		p_array[x] = 0;
}
