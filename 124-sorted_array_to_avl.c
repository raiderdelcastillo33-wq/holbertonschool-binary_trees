#include <stdlib.h>
#include "binary_trees.h"

/**
 * build_avl - Builds or frees an AVL tree
 * @array: Pointer to the sorted array, or NULL to free
 * @start: Start index of the range
 * @end: End index of the range
 * @parent: Pointer to the parent or tree to free
 *
 * Return: Pointer to the root node, or NULL on failure
 */
static avl_t *build_avl(int *array, size_t start, size_t end, avl_t *parent)
{
	avl_t *node;
	size_t middle;

	if (array == NULL)
	{
		if (parent != NULL)
		{
			build_avl(NULL, 0, 0, parent->left);
			build_avl(NULL, 0, 0, parent->right);
			free(parent);
		}
		return (NULL);
	}

	middle = start + ((end - start) / 2);
	node = binary_tree_node(parent, array[middle]);
	if (node == NULL)
		return (NULL);

	if (middle > start)
	{
		node->left = build_avl(array, start, middle - 1, node);
		if (node->left == NULL)
		{
			free(node);
			return (NULL);
		}
	}
	if (middle < end)
	{
		node->right = build_avl(array, middle + 1, end, node);
		if (node->right == NULL)
		{
			build_avl(NULL, 0, 0, node->left);
			free(node);
			return (NULL);
		}
	}
	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl(array, 0, size - 1, NULL));
}
