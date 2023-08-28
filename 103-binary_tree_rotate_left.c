#include "binary_trees.h"

/*Function to perform a left rotation on a binary tree*/
/**
 * binary_tree_rotate_left - Function to perform a left
 * rotation on a binary tree
 * @tree: oldroot
 * Return: newroot
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *newroot, *temp;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}

	newroot = tree->right;
	temp = newroot->left;
	newroot->left = tree;
	tree->right = temp;
	if (temp != NULL)
	{
		temp->parent = tree;
	}
	temp = tree->parent;
	tree->parent = newroot;
	newroot->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
		{
			temp->left = newroot;
		} else
		{
			temp->right = newroot;
		}
	}

	return (newroot);
}
