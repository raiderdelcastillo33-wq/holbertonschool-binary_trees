#include <limits.h>
#include "binary_trees.h"

/**
 * check_avl - Checks BST ordering and AVL balance
 * @tree: Pointer to the current node
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 * @height: Pointer where the subtree height is stored
 *
 * Return: 1 if valid, otherwise 0
 */
static int check_avl(const binary_tree_t *tree, long min, long max,
	int *height)
{
	int left_height, right_height, difference;

	if (tree == NULL)
	{
		*height = 0;
		return (1);
	}

	if ((long)tree->n <= min || (long)tree->n >= max)
		return (0);

	if (!check_avl(tree->left, min, tree->n, &left_height) ||
		!check_avl(tree->right, tree->n, max, &right_height))
		return (0);

	difference = left_height - right_height;
	if (difference < -1 || difference > 1)
		return (0);

	*height = 1 + (left_height > right_height ?
		left_height : right_height);
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid AVL Tree, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height;

	if (tree == NULL)
		return (0);

	return (check_avl(tree, LONG_MIN, LONG_MAX, &height));
}
