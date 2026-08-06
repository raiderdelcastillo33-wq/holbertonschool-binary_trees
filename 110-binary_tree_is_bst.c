#include <limits.h>
#include "binary_trees.h"

/**
 * check_bst - Checks if a binary tree respects BST limits
 * @tree: Pointer to the current node
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 *
 * Return: 1 if valid, otherwise 0
 */
static int check_bst(const binary_tree_t *tree, long min, long max)
{
	if (tree == NULL)
		return (1);

	if ((long)tree->n <= min || (long)tree->n >= max)
		return (0);

	return (check_bst(tree->left, min, tree->n) &&
		check_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (check_bst(tree, LONG_MIN, LONG_MAX));
}
