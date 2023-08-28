#include "binary_trees.h"
/**
 * binary_tree_size - suze of the tree
 * @tree: root node
 * Return: 1 or 0
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	int leftSize = 0, rightSize = 0;

	if (tree == NULL)
	{
		return (0); /*If the tree is empty, it has no nodes, so size is 0.*/
	}

	/*Recursively calculate the size of the left and right subtrees*/
	leftSize = binary_tree_size(tree->left);
	rightSize = binary_tree_size(tree->right);

	/*Return the total size, which is 1 (for the current node)*/
	/* plus the sizes of the left and right subtrees*/
	return (1 + leftSize + rightSize);



}
