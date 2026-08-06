#include "binary_trees.h"

/**
 * check_heap - Checks completeness and max-heap ordering
 * @tree: Pointer to the current node
 * @index: Expected array index of the current node
 * @size: Total number of nodes in the tree
 *
 * Return: 1 if valid, otherwise 0
 */
static int check_heap(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	if (tree->left != NULL && tree->n < tree->left->n)
		return (0);

	if (tree->right != NULL && tree->n < tree->right->n)
		return (0);

	return (check_heap(tree->left, (index * 2) + 1, size) &&
		check_heap(tree->right, (index * 2) + 2, size));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a Max Binary Heap
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid Max Binary Heap, otherwise 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);
	return (check_heap(tree, 0, size));
}
