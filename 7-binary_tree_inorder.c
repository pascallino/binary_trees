#include "binary_trees.h"
/**
 * binary_tree_inorder - inorder tansversal
 * processes the current node in between its left child and right child nodes.
 * @root: root node
 * @func: print function
 */

void binary_tree_inorder(binary_tree_t *root, void (*func)(int))
{

	if (root && func)
	{
		binary_tree_inorder(root->left, (func));
		func(root->n);
		binary_tree_inorder(root->right,  (func));


	}

}

