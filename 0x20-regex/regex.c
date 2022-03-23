#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a given string.
 * @str: regular string
 * @pattern: string that might have regex . and/or regex *
 * Return: 1 if they "match", 0 if not.
 */
int regex_match(char const *str, char const *pattern)
{
	int tmp = 0;

	if (*str == '\0' && *pattern == '\0')
		return (1);
	if ((*str == *pattern || *pattern == '.') && *(pattern + 1) != '*')
		return (regex_match(str + 1, pattern + 1));
	if (*(pattern + 1) == '*')
	{
		if (*str != '\0' && (*str == *pattern || *pattern == '.'))
			tmp = regex_match(str + 1, pattern);
		return (regex_match(str, pattern + 2) || tmp);
	}
	return (0);
}
