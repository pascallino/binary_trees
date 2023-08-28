#include "binary_trees.h"

/**
 * binary_tree_depth - Function to calculate the depth
 * @tree: node to check its depth to its higest parent node
 * Return: int
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	/* Function to calculate the depth of a node in a binary tree*/
	/*Check if the current node (tree) exists and has a parent node*/
	if (tree && tree->parent)
	{
		/*If it does, increment the depth by 1 and recursively calculate*/
		/*the depth of the parent node (tree->parent).*/
		return (1 + binary_tree_depth(tree->parent));
	}
	else
	{
		/*If the current node doesn't exist or has no parent, return 0*/
		/*indicating that this node is at depth 0 (the root node).*/
		return (0);
	}
}
