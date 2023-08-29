#include "binary_trees.h"
/**
 * isBSTHelper - helper function to check if bst is valid
 * @root: node
 * @min: min  c valid value
 * @max: max c valid value
 * Return: int
 */
int isBSTHelper(const binary_tree_t *root, int min, int max)
{
	if (root == NULL)
	{
		return (1); /* An empty tree is a valid BST*/
	}

	if (root->n <= min || root->n >= max)
	{
		return (0); /* Node's value is not within the valid range.*/
	}

	/*Recursively check the left and right subtrees*/
	return (isBSTHelper(root->left, min, root->n) &&
			isBSTHelper(root->right, root->n, max));
}

/* Function to check if a binary tree is a valid BST*/
/**
 * binary_tree_is_bst - function to check if bst is valid
 * @root: node
 * Return: int
 */
int binary_tree_is_bst(const binary_tree_t *root)
{
	if (!root)
		return (0);
	/*Call the helper function with an initial valid range*/
	return (isBSTHelper(root, INT_MIN, INT_MAX));
}

