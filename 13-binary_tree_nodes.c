#include "binary_trees.h"

/**
 * binary_tree_nodes - count node with at least starting from a node
 * @tree: node
 * Return: int
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree)
	{
		count += binary_tree_nodes(tree->left);
		count += binary_tree_nodes(tree->right);
		count += ((tree->left || tree->right)) ? 1 : 0;
	}
	return (count);
}
