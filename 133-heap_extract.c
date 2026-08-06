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
 * highest_bit - Finds the highest power of two in an index
 * @index: Positive heap index
 *
 * Return: Highest power of two not greater than index
 */
static size_t highest_bit(size_t index)
{
	size_t bit = 1;

	while (bit <= index / 2)
		bit *= 2;

	return (bit);
}

/**
 * find_last - Finds a node by its one-based heap index
 * @root: Pointer to the root node
 * @index: One-based index of the node
 *
 * Return: Pointer to the indexed node
 */
static heap_t *find_last(heap_t *root, size_t index)
{
	size_t bit;

	bit = highest_bit(index) / 2;

	while (bit > 0)
	{
		if ((index & bit) == 0)
			root = root->left;
		else
			root = root->right;

		bit /= 2;
	}

	return (root);
}

/**
 * heapify_down - Restores Max Heap ordering from the root
 * @root: Pointer to the root node
 */
static void heapify_down(heap_t *root)
{
	heap_t *largest;
	int value;

	while (root != NULL)
	{
		largest = root;

		if (root->left != NULL && root->left->n > largest->n)
			largest = root->left;

		if (root->right != NULL && root->right->n > largest->n)
			largest = root->right;

		if (largest == root)
			return;

		value = root->n;
		root->n = largest->n;
		largest->n = value;
		root = largest;
	}
}

/**
 * heap_extract - Extracts the root value of a Max Binary Heap
 * @root: Double pointer to the root node
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *last;
	size_t size;
	int value;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;
	size = heap_size(*root);

	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last = find_last(*root, size);
	(*root)->n = last->n;

	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	free(last);
	heapify_down(*root);

	return (value);
}
