#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using the
 * Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, tmp;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size; i++)
	{
		/*loop n times after first loop, because first position is saved,*/
		/*then the second loop iterates until a num after the first*/
		for (j = 0; j < size - 1; j++)
		{
			/*last i elements are sorted already*/
			if (array[j] > array[j + 1])
				/*swap the elements*/
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
