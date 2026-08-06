#include "binary_trees.h"

/**
 * heap_size - Counts the nodes in a binary heap
 * @tree: Pointer to the root node
 *
 * Return: Number of nodes in the heap
 */
static size_t heap_size(const heap_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + heap_size(tree->left) + heap_size(tree->right));
}

/**
 * highest_bit - Finds the highest power of two in an index
 * @index: Positive heap index
 *
 * Return: Highest power of two not greater than index
 */
static size_t highest_bit(size_t index)
{
	size_t bit = 1;

	while (bit <= index / 2)
		bit *= 2;

	return (bit);
}

/**
 * find_parent - Finds the parent of a heap insertion position
 * @root: Pointer to the root node
 * @index: One-based index of the new node
 *
 * Return: Pointer to the parent node
 */
static heap_t *find_parent(heap_t *root, size_t index)
{
	size_t bit;

	bit = highest_bit(index) / 2;

	while (bit > 1)
	{
		if ((index & bit) == 0)
			root = root->left;
		else
			root = root->right;

		bit /= 2;
	}

	return (root);
}

/**
 * bubble_up - Restores Max Heap ordering
 * @node: Pointer to the inserted node
 *
 * Return: Pointer to the node containing the inserted value
 */
static heap_t *bubble_up(heap_t *node)
{
	int value;

	while (node->parent != NULL && node->n > node->parent->n)
	{
		value = node->n;
		node->n = node->parent->n;
		node->parent->n = value;
		node = node->parent;
	}

	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *node;
	size_t index;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	index = heap_size(*root) + 1;
	parent = find_parent(*root, index);
	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);

	if ((index & 1) == 0)
		parent->left = node;
	else
		parent->right = node;

	return (bubble_up(node));
}
