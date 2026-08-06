#include <stdlib.h>
#include "binary_trees.h"

/**
 * value_exists - Checks whether a value exists in an AVL tree
 * @tree: Pointer to the root node
 * @value: Value to search for
 *
 * Return: 1 if the value exists, otherwise 0
 */
static int value_exists(const avl_t *tree, int value)
{
	while (tree != NULL)
	{
		if (value < tree->n)
			tree = tree->left;
		else if (value > tree->n)
			tree = tree->right;
		else
			return (1);
	}

	return (0);
}

/**
 * free_avl - Frees an AVL tree
 * @tree: Pointer to the root node
 */
static void free_avl(avl_t *tree)
{
	if (tree == NULL)
		return;

	free_avl(tree->left);
	free_avl(tree->right);
	free(tree);
}

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t index;

	if (array == NULL || size == 0)
		return (NULL);

	for (index = 0; index < size; index++)
	{
		if (value_exists(tree, array[index]))
			continue;

		if (avl_insert(&tree, array[index]) == NULL)
		{
			free_avl(tree);
			return (NULL);
		}
	}

	return (tree);
}
