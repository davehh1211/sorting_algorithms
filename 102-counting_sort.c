#include "sort.h"
/**
 * _calloc - Write a function that allocates memory for an array
 * @nmemb: variable
 * @size: size of the array
 * Return: nothing
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *av;

	if (nmemb == 0 || size == 0)
		return (NULL);

	av = malloc(nmemb * size);
	if (av == NULL)
		return (NULL);
	for (i = 0; i < (nmemb * size); i++)
	{
		av[i] = '\0';
	}
	return (av);
}
/**
 * maxi - finds the maximum element in the array
 * @array: the array to be sorted
 * @size: size of the array
 * Return: integer of array
 */
int maxi(int *array, size_t size)
{
	unsigned int i = 0;
	int maximum = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > maximum)
		{
			maximum = array[i];
		}
	}
	return (maximum);
}

/**
 * counting_sort - sort array by counting
 * @array: array of list
 * @size: size of the array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	unsigned int i; 
	int idx, *arr, *count;
	int maximum = maxi(array, size);

	count = _calloc(maximum + 1, sizeof(int)); /*only malloc*/
	if (count == NULL)
		return;
	arr = _calloc(size + 1, sizeof(int));
	if (arr == NULL)
		return;

	for (i = 0; i < size; i++) /*starts the count*/
		++count[array[i]];

	for (idx = 1; idx <= maximum; idx++) /*it counts the occurences*/
		count[idx] += count[idx - 1];
	print_array(count, maximum + 1);
	
	for (i = 0; i < size; ++i)
	{
		arr[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; ++i)
		array[i] = arr[i];
	
	free(arr);
	free(count);
}
