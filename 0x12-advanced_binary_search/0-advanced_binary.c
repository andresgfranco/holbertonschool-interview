#include "search_algos.h"

/**
 * print_array - prints and sub array
 * @array: the array
 * @low: start index
 * @size: end index
*/
void print_array(int *array, size_t low, size_t size)
{
	printf("Searching in array: ");

	for (; low < size; low++)
		printf("%d, ", (int)array[low]);
	printf("%d\n", (int)array[low]);
}

/**
 * search_binary - searches for a value in a sorted array of integers
 * @array: the array
 * @low: start index
 * @size: the sub array size
 * @value: value to search
 *
 * Return: index to the value located or -1 if not found
*/
int search_binary(int *array, size_t low, size_t size, int value)
{
	int mid = low + ((size - low) / 2);

	if (low > size)
		return (-1);

	print_array(array, low, size);

	if (array[mid] == value)
	{
		if (mid == 0 || array[mid - 1] != value)
			return (mid);
	}
	else if (array[mid] < value)
	{
		return (search_binary(array, mid + 1, size, value));
	}
	return (search_binary(array, low, mid, value));
}

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: the array
 * @size: the array size
 * @value: value to search
 *
 * Return: index to the value located or -1 if not found
*/
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (search_binary(array, 0, size - 1, value));
}
