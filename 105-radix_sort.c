#include "sort.h"

/**
 * Max - A utility function to get maximum value in arr[]
 * @arr: array to get maximum
 * @n: size of the array
 * Return: integer
 */
int Max(int arr[], unsigned int n)
{
	int mx = arr[0];
	unsigned int i;

	for (i = 1; i < n; i++)
	{
		if (arr[i] > mx)
			mx = arr[i];
	}
	return (mx);
}

/**
 * sortingcount - A function to do counting sort of arr[] according to
 * @array: array to sort
 * @exp: exponent
 * @output: array to allocate info
 * @size: size of the array
 * Return: void
 */
void sortingcount(int *array, int size, int exp, int *output)
{
	int i;
	int count[10] = {0};

    /*Store count of occurrences in count[]*/
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

    /*Change count[i] so that count[i] now contains actual*/
    /*position of this digit in output[]*/
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/*Build the output array*/
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/*Copy the output array to arr[], so that arr[] now*/
	/*contains sorted numbers according to current digit*/
	for (i = 0; i < size; i++)
		array[i] = output[i];
}
/**
 * radix_sort - radix sort
 * @array: array to sort
 * @size: size to array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	/*Find the maximum number to know number of digits*/
	int max = 0;
	int exp, *output = '\0';

	if (array == '\0' || size < 2)
		return;
	/*Do counting sort for every digit. Note that instead */
	/*of passing digit number, exp is passed. exp is 10^i */
	/*where i is current digit number */
	/*output = malloc(sizeof(size));*/
	max = Max(array, size);
	output = malloc(size * sizeof(int));
	if (output == '\0')
		return;
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		sortingcount(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
