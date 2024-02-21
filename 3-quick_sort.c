#include "sort.h"

void swap_ints(int *a, int *b);

int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - function
 * @a: The first integer
 * @b: The second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - function
 * @array: The array
 * @size: The size
 * @left: index
 * @right: index
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int pivot = array[right];
	int i = left - 1;
	int j;

	for (j = left; j < right; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_ints(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap_ints(&array[i + 1], &array[right]);
	print_array(array, size);
	return (i + 1);
}

/**
 * lomuto_sort - function
 * @array: An array
 * @size: The size
 * @left: index
 * @right: index
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	if (left < right)
	{
		int pivot_index = lomuto_partition(array, size, left, right);

		lomuto_sort(array, size, left, pivot_index - 1);
		lomuto_sort(array, size, pivot_index + 1, right);
	}
}

/**
 * * quick_sort - function
 * * @array: An array
 * * @size: The size
 *
 * Description: Uses the Lomuto partition scheme.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
