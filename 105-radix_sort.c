#include "sort.h"

/**
 * get_max - To get the max of the array
 *@array: array to be sorted
 *@size: size to be sorted
 *Author : Darryl Nnon
 * Return: int
 */
int get_max(int *array, int size)
{
	int mx, j;

	for (mx = array[0], j = 1; j < size; j++)
	{
		if (array[i] > mx)
		{
			mx = array[j];
		}
	}
	return (mx);
}

/**
 * lsd_sort - sorting algo
 *@array: array to be sorted
 *@size: size of array to be sorted
 *@exp: exp
 *@copy: copy
 * Return: void
 */
void lsd_sort(int *array, size_t size, int exp, int *copy)
{
	size_t j;
	int bucket[10] = {0};

	for (j = 0; j < size; j++)
	{
		bucket[(array[j] / exp) % 10]++;
	}

	for (j = 1; j < 10; j++)
	{
		bucket[j] = bucket[j] + bucket[j - 1];
	}

	for (j = size - 1; (int)j >= 0; j--)
	{
		copy[bucket[(array[j] / exp) % 10] - 1] = array[j];
		bucket[(array[j] / exp) % 10]--;
	}

	for (j = 0; j < size; j++)
	{
		array[j] = copy[j];
	}
}
/**
 * radix_sort - radix sorting algo function
 *@array: array to be sorted
 *@size: size of array to be sorted
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int mx, exp, *copy;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;

	mx = get_max(array, size);
	for (exp = 1; mx / exp > 0; exp *= 10)
	{
		lsd_sort(array, size, exp, copy);
		print_array(array, size);
	}
	free(copy);
}
