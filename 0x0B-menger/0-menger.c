#include "menger.h"

/**
 * aux - Checks if indices are (1, 1)
 * @i: Row
 * @j: Column
 * Return: 1 if (1, 1), 0 otherwise
 */

int aux(int i, int j)
{
	while (i != 0 && j != 0)
	{
		if (i % 3 == 1 && j % 3 == 1)
			return (0);

		i /= 3, j /= 3;
	}
	return (1);
}

/**
 * menger - Entry point
 * @level: level of the Menger Sponge to draw
 * Return: Nothing
 */
void menger(int level)
{
	int i, j, limit;

	if (level < 0)
		return;

	for (i = 0, limit = pow(3, level); i < limit; i++)
	{
		for (j = 0; j < limit; j++)
		{
			aux(i, j) == 1 ? printf("%c", '#') : printf("%c", ' ');
		}
		printf("\n");
	}
}
