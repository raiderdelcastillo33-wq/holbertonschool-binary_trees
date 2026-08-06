#include "binary_trees.h"

/**
 * insert_node - Inserts a value into an AVL tree as a BST
 * @tree: Double pointer to the root node
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
static avl_t *insert_node(avl_t **tree, int value)
{
	avl_t *current, *parent, *node;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	current = *tree;
	parent = NULL;

	while (current != NULL)
	{
		parent = current;

		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else
			return (NULL);
	}

	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);

	if (value < parent->n)
		parent->left = node;
	else
		parent->right = node;

	return (node);
}

/**
 * rebalance_tree - Rebalances an AVL tree after insertion
 * @tree: Double pointer to the root node
 * @node: Pointer to the inserted node
 */
static void rebalance_tree(avl_t **tree, avl_t *node)
{
	avl_t *current, *rotated;
	int balance;

	current = node->parent;

	while (current != NULL)
	{
		balance = binary_tree_balance(current);
		rotated = current;

		if (balance > 1)
		{
			if (node->n < current->left->n)
				rotated = binary_tree_rotate_right(current);
			else
			{
				binary_tree_rotate_left(current->left);
				rotated = binary_tree_rotate_right(current);
			}
		}
		else if (balance < -1)
		{
			if (node->n > current->right->n)
				rotated = binary_tree_rotate_left(current);
			else
			{
				binary_tree_rotate_right(current->right);
				rotated = binary_tree_rotate_left(current);
			}
		}

		if (rotated->parent == NULL)
			*tree = rotated;

		current = rotated->parent;
	}
}

/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: Double pointer to the root node
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node;

	node = insert_node(tree, value);
	if (node == NULL)
		return (NULL);

	rebalance_tree(tree, node);
	return (node);
}
