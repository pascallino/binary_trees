#include "binary_trees.h"
/**
 * binary_tree_postorder - postorder tansversal
 * after the left child and right child nodes it processes the node it meets.
 * @root: root node
 * @func: print function
 */

void binary_tree_postorder(binary_tree_t *root, void (*func)(int))
{

	if (root && func)
	{
		binary_tree_postorder(root->left, (func));
		binary_tree_postorder(root->right,  (func));
		func(root->n);


	}

}

