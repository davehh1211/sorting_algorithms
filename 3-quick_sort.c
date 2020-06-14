#include "sort.h"
int partition(int *array, ssize_t low, ssize_t hight, size_t size);
void new_quicksort(int *array, ssize_t low, ssize_t high, size_t size);
/**
 * quick_sort - function to quick sort
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	new_quicksort(array, 0, size - 1, size);
}

/**
 * new_quicksort - function 2 to sort an array
 * @array: array to be sorted
 * @low: the first item of the list
 * @high: the last element of the array
 * @size: size of the array
 * Return: void
 */
void new_quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pi = 0;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		new_quicksort(array, low, pi - 1, size);
		new_quicksort(array, pi + 1, high, size);
	}
}
/**
 * partition - function to split the array
 * @array: array to be sorted
 * @low: the first item of the list
 * @hight: the last element of the array
 * @size: size of the array
 * Return: integer
 */
int partition(int *array, ssize_t low, ssize_t hight, size_t size)
{
	int pivot = array[hight];
	int aux;
	ssize_t i = low, j; /*(low - 1)*/

	for (j = low; j < hight; j++) /*higth - 1*/
	{
		if (array[j] < pivot)
		{
			if (array[i] != array[j])
			{
				aux = array[j];
				array[j] = array[i];
				array[i] = aux;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[hight])
	{
		aux = array[hight];
		array[hight] = array[i];
		array[i] = aux;
		print_array(array, size);
	}
	return (i);
}
