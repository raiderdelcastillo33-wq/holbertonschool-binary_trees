#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node after rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;
	binary_tree_t *parent;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	pivot = tree->right;
	parent = tree->parent;

	tree->right = pivot->left;
	if (pivot->left != NULL)
		pivot->left->parent = tree;

	pivot->left = tree;
	pivot->parent = parent;
	tree->parent = pivot;

	if (parent != NULL)
	{
		if (parent->left == tree)
			parent->left = pivot;
		else if (parent->right == tree)
			parent->right = pivot;
	}

	return (pivot);
}
