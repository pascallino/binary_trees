#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST).
 * @root: Pointer to the root node of the tree where the
 * node will be removed.
 * @value: Value to remove from the tree.
 *
 * Return: Pointer to the new root node of the tree after
 * removing the value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		/* Node with one child or no child */
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		/* Node with two children, find the in-order successor */
		temp = root->right;
		while (temp->left != NULL)
			temp = temp->left;

		/* Copy the data of the successor to the current node */
		root->n = temp->n;

		/* Delete the in-order successor */
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}
