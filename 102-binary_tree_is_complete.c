#include "binary_trees.h"
/**
 * size4completebinary - suze of the tree
 * @tree: root node
 * Return: 1 or 0
 */
size_t size4completebinary(const binary_tree_t *tree)
{
	int leftSize = 0, rightSize = 0;

	if (tree == NULL)
	{
		return (0); /*If the tree is empty, it has no nodes, so size is 0.*/
	}

	/*Recursively calculate the size of the left and right subtrees*/
	leftSize = size4completebinary(tree->left);
	rightSize = size4completebinary(tree->right);

	/*Return the total size, which is 1 (for the current node)*/
	/* plus the sizes of the left and right subtrees*/
	return (1 + leftSize + rightSize);
}

/**
 * isComplete - (helper) check if a tree is complete using the index property
 * @tree: root node
 * @i: index of thwe node(left is 2*i + 1) (right is 2*i +2)
 * @size: size of the tree
 * Return: 1 or 0
 */
int isComplete(const binary_tree_t *tree, int i, int size)
{
	/*Return true if the tree is empty*/
	if (tree == NULL)
	{
		return (1);
	}

	/*Check the left subtree*/
	if ((tree->left && 2 * i + 1 >= size) ||
			!isComplete(tree->left, 2 * i + 1, size))
	{
		return (0);
	}

	/*Check the right subtree*/
	if ((tree->right && 2 * i + 2 >= size) ||
			!isComplete(tree->right, 2 * i + 2, size))
	{
		return (0);
	}

	return (1);
}
/**
 * binary_tree_is_complete - check if a tree
 * is complete using the index property
 * @tree: root node
 * Return: 1 or 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = size4completebinary(tree);

	return (isComplete(tree, 0, size));

}
