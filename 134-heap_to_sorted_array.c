#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_size - Counts the nodes in a binary heap
 * @tree: Pointer to the root node
 *
 * Return: Number of nodes in the heap
 */
static size_t heap_size(const heap_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + heap_size(tree->left) + heap_size(tree->right));
}

/**
 * heap_to_sorted_array - Converts a Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap
 * @size: Address where the array size is stored
 *
 * Return: Pointer to the sorted array, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t index, total;

	if (heap == NULL)
	{
		*size = 0;
		return (NULL);
	}

	total = heap_size(heap);
	array = malloc(sizeof(int) * total);
	if (array == NULL)
	{
		*size = 0;
		return (NULL);
	}

	for (index = 0; index < total; index++)
		array[index] = heap_extract(&heap);

	*size = total;
	return (array);
}
