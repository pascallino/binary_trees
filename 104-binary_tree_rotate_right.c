#include "binary_trees.h"

/*Function to perform a left rotation on a binary tree*/
/**
 * binary_tree_rotate_right - Function to perform a left
 * rotation on a binary tree
 * @tree: oldroot
 * Return: newroot
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *newroot, *temp;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}

	newroot = tree->left;
	temp = newroot->right;
	newroot->right = tree;
	tree->left = temp;
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
