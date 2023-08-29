#include "binary_trees.h"
/**
 * custom_find_min - find the minimum node from the left subtree
 * @current_root: node
 * Return: bst min node
 */
bst_t *custom_find_min(bst_t *current_root)
{
	while (current_root->left != NULL)
		current_root = current_root->left;
	return (current_root);
}

/**
 * custom_bst_delete - Delete a node from the BST
 * @current_root: node
 * @tempnode: temp node to delete
 * Return: root node
 */
bst_t *custom_bst_delete(bst_t *current_root, bst_t *tempnode)
{
	bst_t *parent = tempnode->parent;
	bst_t *successor = NULL;

	/*right-child only but no children*/
	if (tempnode->left == NULL)
	{
		if (parent != NULL && parent->left == tempnode)
			parent->left = tempnode->right;
		else if (parent != NULL)
			parent->right = tempnode->right;
		if (tempnode->right != NULL)
			tempnode->right->parent = parent;
		free(tempnode);
		return (parent == NULL ? tempnode->right : current_root);
	}

	/* Left-child only */
	if (tempnode->right == NULL)
	{
		if (parent != NULL && parent->left == tempnode)
			parent->left = tempnode->left;
		else if (parent != NULL)
			parent->right = tempnode->left;
		if (tempnode->left != NULL)
			tempnode->left->parent = parent;
		free(tempnode);
		return (parent == NULL ? tempnode->left : current_root);
	}

	/*A parent with  Two children */
	successor = custom_find_min(tempnode->right);
	tempnode->n = successor->n;

	return (custom_bst_delete(current_root, successor));
}

/**
 * custom_bst_remove_helper -  helper function to delte the target
 * temp node
 * @current_root: root node
 * @value:  node data
 * @tempnode: temp node to delete
 * Return: root
 *
 */
bst_t *custom_bst_remove_helper(bst_t *current_root, bst_t *tempnode,
		int value)
{
	if (tempnode != NULL)
	{
		if (tempnode->n == value)
			return (custom_bst_delete(current_root, tempnode));
		if (tempnode->n > value)
		{
			return (custom_bst_remove_helper(current_root, tempnode->left, value));
		}
		else
		{
		return (custom_bst_remove_helper(current_root, tempnode->right, value));
		}
	}
	return (NULL);
}

/**
 * bst_remove -  a function to remove a node from a BST
 * @tree: tree root
 * @value: the target value to find and remove
 * Return: root of the target tree
 */
bst_t *bst_remove(bst_t *tree, int value)
{
	return (custom_bst_remove_helper(tree, tree, value));
}

