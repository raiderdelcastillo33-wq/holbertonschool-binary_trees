#include "binary_trees.h"

/**
 * tree_depth - Measures the depth of the leftmost leaf
 * @tree: Pointer to the root node of the tree
 *
 * Return: Depth of the leftmost leaf
 */
static size_t tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree != NULL && tree->left != NULL)
	{
		depth++;
		tree = tree->left;
	}

	return (depth);
}

/**
 * is_perfect - Checks recursively if a binary tree is perfect
 * @tree: Pointer to the current node
 * @depth: Expected leaf depth
 * @level: Current level
 *
 * Return: 1 if perfect, otherwise 0
 */
static int is_perfect(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (level == depth);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect(tree->left, depth, level + 1) &&
		is_perfect(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_perfect(tree, tree_depth(tree), 0));
}