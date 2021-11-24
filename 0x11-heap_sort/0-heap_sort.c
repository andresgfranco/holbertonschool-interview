#include "sort.h"

/**
 * swap - swaps two numbers in an array
 *
 * @array: array of integers
 * @size: array size
 * @i: first index
 * @j: second index
*/
void swap(int *array, size_t size, size_t i, size_t j)
{
	size_t tmp = array[i];

	array[i] = array[j];
	array[j] = tmp;

	print_array(array, size);
}

/**
 * heapify - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 *
 * @array: array of integers
 * @sub_size: sub_array size
 * @i: subtree index
 * @size: array size
*/
void heapify(int *array, size_t sub_size, size_t i, size_t size)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < sub_size && array[left] > array[largest])
		largest = left;

	if (right < sub_size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(array, size, i, largest);

		heapify(array, sub_size, largest, size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 *
 * @array: array of integers
 * @size: array size
*/
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, size, 0, i);

		heapify(array, i, 0, size);
	}
}
