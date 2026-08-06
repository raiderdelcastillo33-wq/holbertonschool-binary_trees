#include "binary_trees.h"

/**
 * tree_height - Measures the height of a binary tree in number of nodes
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree
 */
static int tree_height(const binary_tree_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);

	return (right_height + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (tree_height(tree->left) - tree_height(tree->right));
}
