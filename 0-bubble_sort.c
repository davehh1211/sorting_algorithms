#include "sort.h"
/**
* bubble_sort - fulfill the bubble sort of sorting algorythms
* @array: the array to be sorted
* @size: the size of the array
* Return: nothing, void
*/
void bubble_sort(int *array, size_t size)
{
	unsigned int i;
	unsigned int tmp, index;

	for (i = 0; i < size; i++)
	{
		for (index = 0; index < size; index++)
			if (array[index] > array[index + 1] && array[index + 1])
			{
				tmp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = tmp;
				print_array(array, size);
			}
	}
}
