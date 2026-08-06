#include <stdlib.h>
#include "binary_trees.h"

/**
 * find_node - Finds a value in an AVL tree
 * @root: Pointer to the root node
 * @value: Value to find
 *
 * Return: Pointer to the matching node, or NULL
 */
static avl_t *find_node(avl_t *root, int value)
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
 * minimum_node - Finds the minimum node in a subtree
 * @tree: Pointer to the subtree root
 *
 * Return: Pointer to the minimum node
 */
static avl_t *minimum_node(avl_t *tree)
{
	while (tree != NULL && tree->left != NULL)
		tree = tree->left;

	return (tree);
}

/**
 * replace_node - Replaces a node with one of its children
 * @root: Pointer to the current root node
 * @node: Pointer to the node to replace
 * @child: Pointer to the replacing child
 *
 * Return: Pointer to the updated root node
 */
static avl_t *replace_node(avl_t *root, avl_t *node, avl_t *child)
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
 * rebalance_from - Rebalances an AVL tree from a node to the root
 * @root: Pointer to the root node
 * @start: Pointer to the first node to check
 *
 * Return: Pointer to the updated root node
 */
static avl_t *rebalance_from(avl_t *root, avl_t *start)
{
	avl_t *current, *rotated;
	int balance, child_balance;

	current = start;

	while (current != NULL)
	{
		balance = binary_tree_balance(current);
		rotated = current;

		if (balance > 1)
		{
			child_balance = binary_tree_balance(current->left);

			if (child_balance < 0)
				binary_tree_rotate_left(current->left);

			rotated = binary_tree_rotate_right(current);
		}
		else if (balance < -1)
		{
			child_balance = binary_tree_balance(current->right);

			if (child_balance > 0)
				binary_tree_rotate_right(current->right);

			rotated = binary_tree_rotate_left(current);
		}

		if (rotated->parent == NULL)
			root = rotated;

		current = rotated->parent;
	}

	return (root);
}

/**
 * avl_remove - Removes a value from an AVL tree
 * @root: Pointer to the root node
 * @value: Value to remove
 *
 * Return: Pointer to the new root node
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node, *successor, *child, *rebalance_start;

	node = find_node(root, value);
	if (node == NULL)
		return (root);

	if (node->left != NULL && node->right != NULL)
	{
		successor = minimum_node(node->right);
		node->n = successor->n;
		node = successor;
	}

	rebalance_start = node->parent;

	if (node->left != NULL)
		child = node->left;
	else
		child = node->right;

	root = replace_node(root, node, child);
	free(node);

	if (rebalance_start != NULL)
		root = rebalance_from(root, rebalance_start);
	else if (root != NULL)
		root->parent = NULL;

	return (root);
}
