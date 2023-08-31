#include "binary_trees.h"

/**
 * height_r - height of the left sub and right sub
 * @root: root node
 * Return: int
 */
size_t height_r(binary_tree_t *root)
{
	size_t left = 0, right = 0;

	if (root)
	{

		left =   root->left ? 1 + height_r(root->left) : 1;
		right =  root->right ? 1 + height_r(root->right) : 1;
	}
	return ((left > right ? left : right));
}

/**
 * find_min_value_node - Finds the node with the minimum value in an AVL tree.
 * @node: The root node of the subtree to search.
 * Return: A pointer to the node with the minimum value.
 */
avl_t *find_min_value_node(avl_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}
/**
 * avl_remove - Removes a node with a given value from an AVL tree.
 * @root: A pointer to the root node of the AVL tree.
 * @value: The value to remove from the AVL tree.
 * Return: A pointer to the new root node of the
 * tree after removal and rebalancing.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	int balance;
	avl_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			temp = root->left ? root->left : root->right;
			free(root);
			return (temp);
		}
		temp = find_min_value_node(root->right);
		root->n = temp->n;
		root->right = avl_remove(root->right, temp->n);
	}
	/*Rebalance the tree*/
	balance = binary_tree_balance(root);
	if (balance > 1 && value < root->left->n)
		return (binary_tree_rotate_right(root));
	if (balance < -1 && value > root->right->n)
		return (binary_tree_rotate_left(root));
	if (balance > 1 && value > root->left->n)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (balance < -1 && value < root->right->n)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	return (root);
}
