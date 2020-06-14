#include "sort.h"
/**
 * quick_sort - sorts an array of integers in ascending order using the
 * quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	int low, high;

	low = 0;
	high = size - 1;
	quick_recursion(array, low, high, size);
}

/**
 * partition - Implement the Lomuto partition scheme
 * @array: array to be sorted
 * @low: First position of array
 * @high: Last position of array
 * @size: Size of the array
 * Return: i
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];/*pivot*/
	i = low - 1;/*Index of smaller element*/
	for (j = low; j <= high; j++)
	{
		/*If current element is smaller than or equal to pivot*/
		if (array[j] <= pivot)
		{
			i++;/*increment index of smaller element*/
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}
	return (i);
}

/**
 * swap - Function to interchange two positions in array.
 * @array: array to be sorted
 * @i: Position in array.
 * @j: Position in array.
 * Return: void
 */
void swap(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * quick_recursion - Function that implements recursion to call
 * the Quick Sort function.
 * @array: array to be sorted
 * @low: First position of array
 * @high: Last position of array
 * @size: Size of the array
 * Return: void
 */
void quick_recursion(int *array, size_t low, size_t high, size_t size)
{
	size_t idx;

	if (low < high)
	{
		/*idx is partitioning index, "arr[p]" is now at right place*/
		idx = partition(array, low, high, size);
		/*Separately sort elements before partition and after partition*/
		if (idx > low)
			quick_recursion(array, low, idx - 1, size);/*left array*/
		if (idx < high)
			quick_recursion(array, idx + 1, high, size);/*right*/
	}
}
