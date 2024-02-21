#include "sort.h"

/**
 * swap_ints - functoin
 * @a: The first integer
 * @b: The second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - function
 *
 * @array: An array
 * @size: The size.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t j = 0, k;

	if (array == NULL || size < 2)
		return;

	while (j < size - 1)
	{
		min = array + j;
		k = j + 1;
		while (k < size)
		{
			min = (array[k] < *min) ? (array + k) : min;
			k++;
		}

		if ((array + j) != min)
		{
			swap_ints(array + j, min);
			print_array(array, size);
		}
		j++;
	}
}
