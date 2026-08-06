#include "binary_trees.h"

/**
 * tree_size - Counts the nodes in a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Number of nodes in the tree
 */
static size_t tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (tree_size(tree->left) + tree_size(tree->right) + 1);
}

/**
 * check_complete - Checks node positions in a binary tree
 * @tree: Pointer to the current node
 * @index: Expected array index of the current node
 * @size: Total number of nodes in the tree
 *
 * Return: 1 if complete, otherwise 0
 */
static int check_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (check_complete(tree->left, (index * 2) + 1, size) &&
		check_complete(tree->right, (index * 2) + 2, size));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (check_complete(tree, 0, tree_size(tree)));
}
