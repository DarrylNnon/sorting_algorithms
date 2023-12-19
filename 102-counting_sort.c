#include "sort.h"

/**
 * counting_sort - Algorithm that sorts the array in order ascended
 *@array: type array of integers.
 *@size: type size of array.
 * Author: Darryl Nnon
 */

void counting_sort(int *array, size_t size)
{
	int *count, *sort, sum, mx;
	size_t j;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;

	mx = array[0];
	for (j = 1; j < size; j++)
		mx = (array[j] > mx) ? array[j] : mx;
	count = malloc(sizeof(int) * (mx + 1));
	if (count == NULL)
		return;

	for (j = 0; j < (size_t)(mx + 1); j++)
		count[j] = 0;

	for (j = 0; j < size; j++)
		count[array[j]]++;

	for (j = 0, sum = 0; j < (size_t)(mx + 1); j++)
	{
		count[j] += sum;
		sum = count[j];
	}
	print_array(count, mx + 1);

	for (j = 0; j < size; j++)
	{
		sort[count[array[j]] - 1] = array[j];
		count[array[j]]--;
	}
	for (j = 0; j < size; j++)
		array[j] = sort[j];

	free(sort);
	free(count);
}
