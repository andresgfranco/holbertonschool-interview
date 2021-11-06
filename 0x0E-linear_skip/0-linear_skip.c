#include "search.h"

/**
 * find_value - searches for a value in a sorted skip list of integers.
 *
 * @list: is a pointer to the head of the sub list to search in
 * @value: is the value to search for
 *
 * Return: the node if found or NULL if not
*/
skiplist_t *find_value(skiplist_t *list, int value)
{
	skiplist_t *tmplist = list;
	char *outputf_checked = "Value checked at index [%ld] = [%d]\n";

	while (tmplist)
	{
		printf(
			outputf_checked,
			tmplist->index,
			tmplist->n
		);
		if (tmplist->n == value)
			return (tmplist);

		tmplist = tmplist->next;
	}

	return (NULL);
}

/**
 * linear_skip - searches for a value in a sorted skip list of integers.
 *
 * @list: is a pointer to the head of the skip list to search in
 * @value: is the value to search for
 *
 * Return: the node if found or NULL if not
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp_express = NULL, *last_index = NULL;
	char *outputf_checked = "Value checked at index [%ld] = [%d]\n";
	char *outputf_found = "Value found between indexes [%ld] and [%ld]\n";

	if (!list)
		return (NULL);

	tmp_express = list;

	while (tmp_express->express)
	{
		printf(outputf_checked, tmp_express->express->index,
			tmp_express->express->n
		);

		if (tmp_express->express->n >= value)
		{
			printf(outputf_found, tmp_express->index,
				tmp_express->express->index
			);

			return (find_value(tmp_express, value));
		}
		else if (!tmp_express->express->express)
		{
			last_index = tmp_express->express;
			while (last_index->next)
				last_index = last_index->next;

			printf(outputf_found, tmp_express->express->index,
				last_index->index
			);

			return (find_value(tmp_express->express, value));
		}

		tmp_express = tmp_express->express;
	}

	return (NULL);
}
