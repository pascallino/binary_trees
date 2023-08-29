#include "binary_trees.h"

/**
 * binary_tree_height - height of the left sub and right sub
 * @root: root node
 * Return: int
 */
size_t binary_tree_height(binary_tree_t *root)
{
	size_t left = 0, right = 0;

	if (root)
	{

		left =   root->left ? 1 + binary_tree_height(root->left) : 1;
		right =  root->right ? 1 + binary_tree_height(root->right) : 1;
	}
	return ((left > right ? left : right));
}

/**
 * binary_tree_balance - tree balance factor
 * @tree: tree node
 * Return: 1 or  0
 */
int binary_tree_balance(const binary_tree_t *tree)
{

	int left = 0, right = 0;

	if (!tree)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	return (left - right);
}
