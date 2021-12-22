#include "holberton.h"

/**
 * print_num - prints an array of ints
 * @arrint: array of integers
 * @size: size array
 */
void print_num(int *arrint, int size)
{
	int i;

	if (!arrint && !size)
	{
		printf("0\n");
		exit(0);
	}

	for (i = 0; arrint[i] == 0; i++)
		;

	while (i < size)
	{
		printf("%d", arrint[i]);
		i++;
	}
	printf("\n");
}

/**
 * multiply - multiplies two large numbers
 * @stri1: string of large int
 * @stri2: string  of large int
 * Return: 1 on success
 */
int multiply(char *stri1, char *stri2)
{
	int i, j;
	int len1, len2, sum, n1, n2 = 0;
	int *arrint;

	len1 = strlen(stri1);
	len2 = strlen(stri2);

	arrint = calloc(len1 + len2, sizeof(len1 + len2));
	if (!arrint)
		return (0);

	i = len1 - 1;

	while (i >= 0)
	{
		n1 = stri1[i] - '0';
		j = len2 - 1;
		while (j >= 0)
		{
			n2 = stri2[j] - '0';
			sum = (n1 * n2) + arrint[i + j + 1];
			arrint[i + j] += sum / 10;
			arrint[i + j + 1] = sum % 10;
			j--;
		}
		i--;
	}

	print_num(arrint, len1 + len2);
	free(arrint);
	return (1);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments passed
 * @argv: arguments passed
 * Return: 0 in success,
 */
int main(int argc, char **argv)
{
	int i, j = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = 1; argv[i]; i++)
		for (j = 0; argv[i][j]; j++)
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				exit(98);

			}

	if (*argv[1] == '0' || *argv[2] == '0')
		print_num(NULL, 0);

	if (!multiply(argv[1], argv[2]))
		return (1);

	return (0);
}
