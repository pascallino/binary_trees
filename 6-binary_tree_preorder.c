#include "binary_trees.h"
/**
 * binary_tree_preorder - preorder tansversal ,
 * move left and left subtress then move right then left
 * @root: root node
 * @func: print function
 */

void binary_tree_preorder(binary_tree_t *root, void (*func)(int))
{

	if (root && func)
	{
		func(root->n);
		binary_tree_preorder(root->left, (func));
		binary_tree_preorder(root->right,  (func));


	}

}

