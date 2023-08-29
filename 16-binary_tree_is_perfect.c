#include "binary_trees.h"

/**
 * tree_height - height of a tree
 * @root: nodes
 * Return: height
 */

size_t tree_height(const binary_tree_t *root)
{
	size_t left = 0, right = 0;

	if (root)
	{

		left =   root->left ? 1 + tree_height(root->left) : 0;
		right =  root->right ? 1 + tree_height(root->right) : 0;
	}
	return ((left > right ? left : right));
}

/**
 * binary_tree_is_perfect - check if tree is perfect
 * @tree: node
 * Return: 0 or 1
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int level;

	if (tree == NULL)
		return (0);

	level = tree_height(tree);

	return (isPerfectBinaryTree(tree, 0, level));

}

/**
 * isPerfectBinaryTree - check if tree is perfect helper
 * @root: node
 * @depth: depth of tree
 * @level: height
 * Return: 0 or 1
 */
int isPerfectBinaryTree(const binary_tree_t *root, int depth, int level)
{
	if (root == NULL)
	{
		return (1);
	}
	/* If a node has one child but not both, the tree is not perfect.*/
	if ((root->left == NULL && root->right != NULL) ||
			(root->left != NULL && root->right == NULL))
	{
		return (0);
	}
	/*If the current node is a leaf node, check if its*/
	/*depth matches the overall level.*/
	if (root->left == NULL && root->right == NULL)
	{
		return (depth == level);
	}
	/*Recursively check the left and right subtrees with updated depth and level*/
	return (isPerfectBinaryTree(root->left, depth + 1, level) &&
			isPerfectBinaryTree(root->right, depth + 1, level));

}
