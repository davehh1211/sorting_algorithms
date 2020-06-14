#include "sort.h"
/**
* selection_sort - sort of selection
* @array: array to be sorted
* @size: size of the array
* Return: void
*/
void selection_sort(int *array, size_t size)
{
	int aux = 0;
	unsigned int minimum = 0;
	unsigned int i = 0, j = 0;

	for (i = 0; i < size - 1; i++)
	{
		minimum = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minimum])
			{
				minimum = j;
			}
		}
		if (minimum != i)
		{
			aux = array[minimum];
			array[minimum] = array[i];
			array[i] = aux;
			print_array(array, size);
		}
	}
}
