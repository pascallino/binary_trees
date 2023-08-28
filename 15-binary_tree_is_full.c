#include "binary_trees.h"
/**
 * binary_tree_is_full - check if binary tree is full
 * @tree: node to start the check
 * Return: 1 or 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{

	if (!tree)
		return (0);

	return (is_treeFull(tree));
}

/**
 * is_treeFull - check if binary tree is full
 * @tree: node to start the check
 * Return: 1 or 0
 */
int is_treeFull(const binary_tree_t *tree)
{

	if (!tree)
	{
		return (1);
	}

	if (tree)
	{
		if ((tree->left == NULL && tree->right != NULL) ||
				(tree->left != NULL && tree->right == NULL))
		{
			return (0);
		}


	}

	/* Recursively check the left and right subtrees */
	return (is_treeFull(tree->left) && is_treeFull(tree->right));
}
