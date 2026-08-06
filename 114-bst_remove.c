#include <stdlib.h>
#include "binary_trees.h"

/**
 * find_node - Finds a value in a Binary Search Tree
 * @root: Pointer to the root node
 * @value: Value to find
 *
 * Return: Pointer to the matching node, or NULL
 */
static bst_t *find_node(bst_t *root, int value)
{
	while (root != NULL)
	{
		if (value < root->n)
			root = root->left;
		else if (value > root->n)
			root = root->right;
		else
			return (root);
	}

	return (NULL);
}

/**
 * minimum_node - Finds the minimum node in a BST
 * @tree: Pointer to the root node
 *
 * Return: Pointer to the minimum node
 */
static bst_t *minimum_node(bst_t *tree)
{
	while (tree != NULL && tree->left != NULL)
		tree = tree->left;

	return (tree);
}

/**
 * replace_node - Replaces a node with one of its children
 * @root: Pointer to the root node
 * @node: Pointer to the node to replace
 * @child: Pointer to the replacing child
 *
 * Return: Pointer to the root node
 */
static bst_t *replace_node(bst_t *root, bst_t *node, bst_t *child)
{
	if (node->parent == NULL)
		root = child;
	else if (node->parent->left == node)
		node->parent->left = child;
	else
		node->parent->right = child;

	if (child != NULL)
		child->parent = node->parent;

	return (root);
}

/**
 * bst_remove - Removes a value from a Binary Search Tree
 * @root: Pointer to the root node of the BST
 * @value: Value to remove
 *
 * Return: Pointer to the new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *successor, *child;

	node = find_node(root, value);
	if (node == NULL)
		return (root);

	if (node->left != NULL && node->right != NULL)
	{
		successor = minimum_node(node->right);
		node->n = successor->n;
		node = successor;
	}

	if (node->left != NULL)
		child = node->left;
	else
		child = node->right;

	root = replace_node(root, node, child);
	free(node);

	return (root);
}
