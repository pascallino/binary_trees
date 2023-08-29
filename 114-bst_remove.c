#include "binary_trees.h"

/*Function to find the minimum value node in a BST*/
/**
 * findMinNode - node
 * @node: node
 * Return: node
 */
bst_t *findMinNode(bst_t *node)
{
	while (node->left != NULL)
	{
		node = node->left;
	}
	return (node);
}

/*Function to remove a node with a given value from a BST*/
/**
 * bst_remove - Remove the node with a given value
 * @root: target node
 * @value: node value
 * Return: node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL;

	if (root == NULL)
	{
		return (NULL); /*If the tree is empty, return NULL.*/
	}

	/*Search for the node with the given value*/
	if (value < root->n)
	{
		root->left = bst_remove(root->left, value); /*Search in the left subtree*/
	}
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value); /*Search in the right subtree*/
	}
	else
	{
		/*Node with the given value is found*/

		/*Case 1: Node with only one child or no child*/
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
		/*Case 2: Node with two children*/
		temp = findMinNode(root->right); /*Find the in-order successor*/
		root->n = temp->n; /*Copy the in-order successor's value to this node*/
		root->right = bst_remove(root->right, temp->n);
		/*Delete the in-order successor*/
	}
	return (root);
}
