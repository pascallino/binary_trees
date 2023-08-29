#include "binary_trees.h"

/**
 * avlheight - height of a tree
 * @root: nodes
 * Return: height
 */

size_t avlheight(binary_tree_t *root)
{
	size_t left = 0, right = 0;

	if (root)
	{

		left =   root->left ? 1 + avlheight(root->left) : 0;
		right =  root->right ? 1 + avlheight(root->right) : 0;
	}
	return ((left > right ? left : right));
}

/**
 * binary_tree_is_avl_helper -  helper
 * Checks if a binary tree is a valid AVL Tree.
 * @tree: A pointer to the root node of the tree to check.
 * @low: low
 * @high: high
 * Return: 1 if the tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl_helper(const binary_tree_t *tree, int low
		, int high)
{
	size_t left, right, rem;


	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);

		left = avlheight(tree->left);
		right = avlheight(tree->right);
		rem = left > right ? left - right : right - left;
		if (rem > 1)
			return (0);
		return (binary_tree_is_avl_helper(tree->left, low, tree->n - 1) &&
				binary_tree_is_avl_helper(tree->right, tree->n + 1, high));
	}
	return (1);
}



/**
 * binary_tree_is_avl -  Checks if a binary tree is a valid AVL Tree.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if the tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_is_avl_helper(tree, INT_MIN, INT_MAX));
}
