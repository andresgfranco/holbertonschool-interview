#include "slide_line.h"

void slider(int *line, size_t size, int direction);

/**
 * slide_line - slides and merges an array of integers
 *
 * @line: the array
 * @size: the array size
 * @direction: the direction in which to slides the array
 *
 * Return: 1 or 0 in case of failure
 */
int slide_line(int *line, size_t size, int direction)
{
	int i = 0, j = 0, k = 0;
	int before = 0, current = 0;

	if (!line)
		return (0);

	if (direction)
		i -= size - 1;
	else
		j = size - 1;

	for (; i <= j; i++)
	{
		k = i + 1;
		before = i;

		if (direction)
			before *= -1;

		if (line[before])
		{
			for (; k <= j; k++)
			{
				current = k;

				if (direction)
					current *= -1;

				if (line[current] == line[before]) /* MERGE */
				{
					line[before] *= 2;
					line[current] = 0;
					break;
				}
			}
		}
	}

	slider(line, size, direction);

	return (1);
}

/**
 * slider - slides an array of integers
 *
 * @line: the array
 * @size: the array size
 * @direction: the direction in which to slides the array
 */
void slider(int *line, size_t size, int direction)
{
	int i = 0, j = 0, k = 0;
	int before = 0, current = 0;

	if (direction)
		i -= size - 1;
	else
		j = size - 1;

	for (; i <= j; i++)
	{
		k = i + 1;
		before = i;

		if (direction)
			before *= -1;

		if (line[before] == 0)
		{
			for (; k <= j; k++)
			{
				current = k;

				if (direction)
					current *= -1;

				if (line[current])
				{
					line[before] = line[current];
					line[current] = 0;
					break;
				}
			}
		}
	}
}
