#include "binary_trees.h"

/**
 * binary_tree_is_root - Function to check if a node is a root
 * @node:  treeNode
 * Return: 0,1
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node || node->parent)
		return (0);
	return (1);
}
