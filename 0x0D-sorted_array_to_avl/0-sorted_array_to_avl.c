#include "binary_trees.h"
#include <unistd.h>

/**
 * create_node - creates a avl_t node
 *
 * Return: the node created or NULL on failure
*/
avl_t *create_node()
{
	avl_t *node = NULL;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 *
 * @array: is a pointer to the first element of the array to be converted
 * @size: the array size
 *
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t half;

	if (!array || size == 0)
		return (NULL);

	half = (size / 2);

	root = create_node();
	if (!root)
		return (NULL);

	if (size == 1)
	{
		root->n = array[0];
		return (root);
	}

	if (size % 2 == 0)
	{
		root->n = array[half - 1];
		root->left = sorted_array_to_avl(array, half - 1);
		root->right = sorted_array_to_avl((array + half), half);
	}
	else
	{
		root->n = array[half];
		root->left = sorted_array_to_avl(array, half);
		root->right = sorted_array_to_avl((array + half + 1), half);
	}

	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;

	return (root);
}
