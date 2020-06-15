#include "sort.h"

/**
 * shell_sort - Sorts an array of integers with Shell sort algorithm.
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t n = 1, i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	/*Calculate the interval used to compare*/
	while (n < size / 3)
		n = n * 3 + 1;

	while (n > 0)
	{
		i = n;
		while (i < size)
		{
			/*Stores value in tmp variable*/
			tmp = array[i];
			j = i;
			/*
			 * Moves to right and compares if
			 * tmp is less than another value found with interval
			 */
			while (j > (n - 1) && tmp < array[j - n])
			{
				/*Stores the value of another position*/
				array[j] = array[j - n];
				j = j - n;
			}
			/*Assign value of tmp*/
			array[j] = tmp;
			i++;
		}
		/*Reduces the interval of comparison of the numbers*/
		n = (n - 1) / 3;
		print_array(array, size);
	}
}
