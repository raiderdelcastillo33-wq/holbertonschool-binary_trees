#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node after rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;
	binary_tree_t *parent;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	pivot = tree->left;
	parent = tree->parent;

	tree->left = pivot->right;
	if (pivot->right != NULL)
		pivot->right->parent = tree;

	pivot->right = tree;
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
