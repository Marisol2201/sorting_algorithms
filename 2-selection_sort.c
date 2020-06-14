#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using the
 * Selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, minimum, temp;

	/*reduces the effective size of the array by one in  each iteration*/
	for (i = 0; i < size - 1; i++)
	{
		/*assuming the first element to be the minimum of the unsorted array*/
		minimum = i;
		/*gives the effective size of the unsorted array*/
		for (j = i + 1; j < size; j++)
		{
			/*finds the minimum element*/
			if (array[j] < array[minimum])
				minimum = j;
		}
		if (minimum != i)
		{
			/*swap the elements*/
			temp = array[i];
			array[i] = array[minimum];
			array[minimum] = temp;
			print_array(array, size);
		}
	}
}
