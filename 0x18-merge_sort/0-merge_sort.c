#include "sort.h"

int *divide_and_conquer(int *array, size_t size, int *buffer);
int *merge(
	int *left_array, int *right_array,
	size_t left_size, size_t right_size,
	int *buffer
);
void copy_buffer(int *left_array, int *buffer, size_t buffer_size);

/**
 * merge_sort - sorts an array of integers in ascending order
 * @array: the array of integers
 * @size: the array size
*/
void merge_sort(int *array, size_t size)
{
	int *buffer = NULL;

	if (!array)
		return;

	buffer = malloc(sizeof(int *) * size);
	if (!buffer)
		return;

	divide_and_conquer(array, size, buffer);

	free(buffer);
}

/**
 * divide_and_conquer - conquer or die
 * @array: the array -_-
 * @size: the array size -_-
 * @buffer: the buffer -_-
 *
 * Return: merged array
*/
int *divide_and_conquer(int *array, size_t size, int *buffer)
{
	int *left_array, *right_array = NULL;
	size_t left_size, right_size;

	if (size == 1)
		return (array);

	left_size = size / 2;
	right_size = left_size;

	if (size % 2 != 0)
		right_size++;

	left_array = divide_and_conquer(array, left_size, buffer);
	right_array = divide_and_conquer(&array[left_size], right_size, buffer);

	return (merge(left_array, right_array, left_size, right_size, buffer));
}

/**
 * merge - merges both arrays in buffer
 * @left_array: left sub array
 * @right_array: right sub array
 * @left_size: array left size
 * @right_size: array right size
 * @buffer: here will merged both arrays
 *
 * Return: merged array
*/
int *merge(
	int *left_array, int *right_array,
	size_t left_size, size_t right_size,
	int *buffer
)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: "), print_array(left_array, left_size);
	printf("[right]: "), print_array(right_array, right_size);

	while (i < left_size && j < right_size)
	{
		if (left_array[i] < right_array[j])
		{
			buffer[k] = left_array[i];

			i++;
		}
		else
		{
			buffer[k] = right_array[j];

			j++;
		}

		k++;
	}

	while (i < left_size)
	{
		buffer[k] = left_array[i];
		i++, k++;
	}

	while (j < right_size)
	{
		buffer[k] = right_array[j];
		j++, k++;
	}

	copy_buffer(left_array, buffer, k);

	return (left_array);
}

/**
 * copy_buffer - copy buffer to left array
 * @left_array: left subArray
 * @buffer: the buffer with left and right arrays merged
 * @buffer_size: buffer size
*/
void copy_buffer(int *left_array, int *buffer, size_t buffer_size)
{
	size_t i = 0;

	while (i < buffer_size)
	{
		left_array[i] = buffer[i];

		i++;
	}

	printf("[Done]: ");
	print_array(left_array, buffer_size);
}
