#include "binary_trees.h"
/**
 * binary_tree_delete - delete an entire tree
 * @tree: root node
 */
void binary_tree_delete(binary_tree_t *tree)
{

	if (tree)
	{
		binary_tree_delete(tree->right);
		binary_tree_delete(tree->left);

		free(tree);
	}



}
