#include "binary_trees.h"

/**
 * binary_tree_leaves - count leafs starting from a node
 * @tree: node
 * Return: int
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree)
	{
		count += binary_tree_leaves(tree->left);
		count += binary_tree_leaves(tree->right);
		count += ((tree->left == NULL && tree->right == NULL)) ? 1 : 0;
	}
	return (count);
}
