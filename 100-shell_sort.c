#include "sort.h"
/**
 * shell_sort - shell sort with Knuth sequence
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	unsigned int interval = 1, i, j = 0, aux;

	if (array == NULL || size < 2)
	{
		return;
	}

	while (interval < size / 3)
	{
		interval = 3 * interval + 1;
	}
	while (interval >= 1)
	{
		for (i = interval; i < size; i++)
		{
			for (j = i; j >= interval && (array[j] < array[j - interval]);
			j -= interval)
			{
				aux = array[j];
				array[j] = array[j - interval];
				array[j - interval] = aux;
			}
		}
		interval /= 3;
		print_array(array, size);
	}
}
