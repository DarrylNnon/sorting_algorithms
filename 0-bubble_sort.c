#include "sort.h"

/**
 * swap_bubble - function for sorting with swap method.
 *@a: element to be swapped.
 *@b: element to be swapped.
 * Return: nothing.
 * Author: Darryl Nnon
 */

void swap_bubble(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - sorts an array using bubble sort algorithm.
 *@array: array to be sorted.
 *@size: size to be sorted.
 * Return: void.
 */

void bubble_sort(int *array, size_t size)
{
	size_t j, sz = size;
	bool booln = false;

	if (array == NULL || size < 2)
		return;

	while (booln == false)
	{
		booln = true;
		for (j = 0; j < sz - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_bubble(array + j, array + j + 1);
				print_array(array, size);
				booln = false;
			}
		}
		sz--;
	}
}
