#include "binary_trees.h"

/**
 * avl_height - height of the left sub and right sub
 * @root: root node
 * Return: int
 */
size_t avl_height(binary_tree_t *root)
{
	size_t left = 0, right = 0;

	if (root)
	{

		left =   root->left ? 1 + avl_height(root->left) : 1;
		right =  root->right ? 1 + avl_height(root->right) : 1;
	}
	return ((left > right ? left : right));
}

/**
 * tree_balance - tree balance factor
 * @tree: tree node
 * Return: 1 or  0
 */
int tree_balance(const binary_tree_t *tree)
{

	int left = 0, right = 0;

	if (!tree)
		return (0);

	left = avl_height(tree->left);
	right = avl_height(tree->right);

	return (left - right);
}

/**
 * avl_insert_helper - recursive insert into Adelson-Velsky and Landis tree
 * @root: ==========
 * @parent: =============
 * @new_node: ======================
 * @value: T=======
 * Return: the new root
 */
avl_t *avl_insert_helper(avl_t **root, avl_t *parent,
		avl_t **new_node, int value)
{
	int balance_factor;

	if (!*root)
		return (*new_node = binary_tree_node(parent, value));

	if ((*root)->n > value)
	{
		(*root)->left = avl_insert_helper(&(*root)->left, *root, new_node, value);
		if (!(*root)->left)
			return (NULL);
	}
	else if ((*root)->n < value)
	{
		(*root)->right = avl_insert_helper(&(*root)->right, *root, new_node, value);
		if (!(*root)->right)
			return (NULL);
	}
	else
		return (*root);

	balance_factor = tree_balance(*root);
	if (balance_factor > 1 && (*root)->left->n > value)
		*root = binary_tree_rotate_right(*root);
	else if (balance_factor < -1 && (*root)->right->n < value)
		*root = binary_tree_rotate_left(*root);
	else if (balance_factor > 1 && (*root)->left->n < value)
	{
		(*root)->left = binary_tree_rotate_left((*root)->left);
		*root = binary_tree_rotate_right(*root);
	}
	else if (balance_factor < -1 && (*root)->right->n > value)
	{
		(*root)->right = binary_tree_rotate_right((*root)->right);
		*root = binary_tree_rotate_left(*root);
	}

	return (*root);
}

/**
 * avl_insert- AVL insert
 * @tree: double pointer root node
 * @value: value to be added
 * Return: the new node or null
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_helper(tree, *tree, &new_node, value);
	return (new_node);
}

