#include "binary_trees.h"

/**
 * node_depth - Measures the depth of a node
 * @node: Pointer to the node
 *
 * Return: Depth of the node
 */
static size_t node_depth(const binary_tree_t *node)
{
	size_t depth = 0;

	while (node != NULL && node->parent != NULL)
	{
		depth++;
		node = node->parent;
	}

	return (depth);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor, or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	size_t first_depth, second_depth;

	if (first == NULL || second == NULL)
		return (NULL);

	first_depth = node_depth(first);
	second_depth = node_depth(second);

	while (first_depth > second_depth)
	{
		first = first->parent;
		first_depth--;
	}

	while (second_depth > first_depth)
	{
		second = second->parent;
		second_depth--;
	}

	while (first != NULL && second != NULL)
	{
		if (first == second)
			return ((binary_tree_t *)first);

		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}
