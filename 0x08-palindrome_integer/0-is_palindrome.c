#include "palindrome.h"

int rec_palindrome(unsigned long *n, unsigned long ten, unsigned long tmp);

/**
 * is_palindrome - checks whether or not a given unsigned integer
 * is a palindrome.
 *
 * @n: is the number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
*/
int is_palindrome(unsigned long n)
{
	return (rec_palindrome(&n, 10, n));
}

/**
 * rec_palindrome - checks whether or not a given unsigned integer
 * is a palindrome.
 *
 * @n: is the number to be checked
 * @moon: helps to find @n size
 * @tmp: temporal variable of @n
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
*/
int rec_palindrome(unsigned long *n, unsigned long ten, unsigned long tmp)
{
	unsigned long module = 0;

	module = tmp % ten;
	tmp = tmp / ten;

	if (tmp > 0)
		if (!rec_palindrome(n, ten, tmp))
			return (0);

	tmp = *n % ten;
	*n /= ten;

	if (tmp != module)
		return (0);

	return (1);
}
