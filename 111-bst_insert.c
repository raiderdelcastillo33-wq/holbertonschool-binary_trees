#include "binary_trees.h"

/**
 * find_parent - Finds the parent for a new BST node
 * @tree: Pointer to the root node
 * @value: Value to insert
 *
 * Return: Pointer to the parent, or NULL if value already exists
 */
static bst_t *find_parent(bst_t *tree, int value)
{
	while (tree != NULL)
	{
		if (value < tree->n)
		{
			if (tree->left == NULL)
				return (tree);
			tree = tree->left;
		}
		else if (value > tree->n)
		{
			if (tree->right == NULL)
				return (tree);
			tree = tree->right;
		}
		else
			return (NULL);
	}

	return (NULL);
}

/**
 * bst_insert - Inserts a value into a Binary Search Tree
 * @tree: Double pointer to the root node of the BST
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *parent, *node;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	parent = find_parent(*tree, value);
	if (parent == NULL)
		return (NULL);

	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);

	if (value < parent->n)
		parent->left = node;
	else
		parent->right = node;

	return (node);
}
