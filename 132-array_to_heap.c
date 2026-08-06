#include <stdlib.h>
#include "binary_trees.h"

/**
 * free_heap - Frees a Binary Heap
 * @tree: Pointer to the root node
 */
static void free_heap(heap_t *tree)
{
	if (tree == NULL)
		return;

	free_heap(tree->left);
	free_heap(tree->right);
	free(tree);
}

/**
 * array_to_heap - Builds a Max Binary Heap from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node, or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *tree = NULL;
	size_t index;

	if (array == NULL || size == 0)
		return (NULL);

	for (index = 0; index < size; index++)
	{
		if (heap_insert(&tree, array[index]) == NULL)
		{
			free_heap(tree);
			return (NULL);
		}
	}

	return (tree);
}
