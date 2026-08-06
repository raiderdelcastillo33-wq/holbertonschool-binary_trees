#include <stdlib.h>
#include "binary_trees.h"

/**
 * value_exists - Checks whether a value exists in a BST
 * @tree: Pointer to the root node
 * @value: Value to search for
 *
 * Return: 1 if the value exists, otherwise 0
 */
static int value_exists(const bst_t *tree, int value)
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
 * free_bst - Frees a Binary Search Tree
 * @tree: Pointer to the root node
 */
static void free_bst(bst_t *tree)
{
	if (tree == NULL)
		return;

	free_bst(tree->left);
	free_bst(tree->right);
	free(tree);
}

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t index;

	if (array == NULL || size == 0)
		return (NULL);

	for (index = 0; index < size; index++)
	{
		if (value_exists(tree, array[index]))
			continue;

		if (bst_insert(&tree, array[index]) == NULL)
		{
			free_bst(tree);
			return (NULL);
		}
	}

	return (tree);
}
