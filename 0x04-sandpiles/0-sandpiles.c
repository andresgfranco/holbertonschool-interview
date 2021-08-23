#include "sandpiles.h"

/**
 * print_grid - Print grid 3x3
 * @grid: grid 2d
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - sums sandpiles
 *
 * @grid1: the first grid 3x3
 * @grid2: the second grid 3x3
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int overflow = 0;
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			grid2[i][j] = check_overflow(grid1[i][j], &overflow);
		}

	if (overflow)
		loop_and_overflow(grid1, grid2);
}

/**
 * loop_and_overflow - loops the "sandpile grid"
 * and overflow a cell if is necessary
 *
 * @grid1: the first grid 3x3
 * @grid2: the second grid 3x3
*/
void loop_and_overflow(int grid1[3][3], int grid2[3][3])
{
	int overflow = 0, i, j;

	while (1)
	{
		print_grid(grid1);

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3 && grid2[i][j] == 1)
				{
					if (i - 1 >= 0 && i - 1 < 3) /* UP */
					{
						grid1[i - 1][j] += 1;
						grid2[i - 1][j] = check_overflow(grid1[i - 1][j], &overflow);
					}

					if (j + 1 >= 0 && j + 1 < 3) /* RIGHT */
						grid1[i][j + 1] += 1;

					if (i + 1 >= 0 && i + 1 < 3) /* DOWN */
						grid1[i + 1][j] += 1;

					if (j - 1 >= 0 && j - 1 < 3) /* LEFT */
					{
						grid1[i][j - 1] += 1;
						grid2[i][j - 1] = check_overflow(grid1[i][j - 1], &overflow);
					}
					grid1[i][j] -= 4;
				}
				grid2[i][j] = check_overflow(grid1[i][j], &overflow);
			}
		}

		if (overflow)
			overflow = 0;
		else
			break;
	}
}

/**
 * check_overflow - check if a number is greater than 3
 * @num: the number to check, is from the sandpile grid
 * @over: a pointer to the control variable in loop_and_overflow func
 *
 * Return: 1 if is greater than 3 or 0 if not
*/
int check_overflow(int num, int *over)
{
	if (num > 3)
	{
		*over = 1;
		return (1);
	}
	return (0);
}
