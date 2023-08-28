#include "binary_trees.h"

/**
 * binary_tree_height - height of a tree
 * @root: nodes
 * Return: height
 */

size_t binary_tree_height(binary_tree_t *root)
{
	size_t left = 0, right = 0;

	if (root)
	{

		left =   root->left ? 1 + binary_tree_height(root->left) : 0;
		right =  root->right ? 1 + binary_tree_height(root->right) : 0;
	}
	return ((left > right ? left : right));
}
