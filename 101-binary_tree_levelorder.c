#include "binary_trees.h"

/**
 * tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height of the tree
 */
static size_t tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);

	return (right_height + 1);
}

/**
 * visit_level - Calls a function for every node at a given level
 * @tree: Pointer to the root node
 * @func: Pointer to the function to call
 * @level: Level to visit
 */
static void visit_level(const binary_tree_t *tree, void (*func)(int),
	size_t level)
{
	if (tree == NULL)
		return;

	if (level == 1)
	{
		func(tree->n);
		return;
	}

	visit_level(tree->left, func, level - 1);
	visit_level(tree->right, func, level - 1);
}

/**
 * binary_tree_levelorder - Traverses a binary tree using level order
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, level;

	if (tree == NULL || func == NULL)
		return;

	height = tree_height(tree);

	for (level = 1; level <= height; level++)
		visit_level(tree, func, level);
}
