#include "binary_trees.h"

/**
 * height4levelorder - height of a tree
 * @root: nodes
 * Return: height
 */

size_t height4levelorder(const binary_tree_t *root)
{
	size_t left = 0, right = 0;

	if (root)
	{

		left =   root->left ? 1 + height4levelorder(root->left) : 0;
		right =  root->right ? 1 + height4levelorder(root->right) : 0;
	}
	return ((left > right ? left : right));
}

/**
 * binary_levelorder_helper - helper function to move
 * from level to level for each node
 * @tree: node
 * @func: print function
 * @level: level of the node
 */

void binary_levelorder_helper(const binary_tree_t *tree,
		void (*func)(int), size_t level)
{

	if (level == 1)
	{
		func(tree->n);
	}
	else
	{
		binary_levelorder_helper(tree->left, func, level - 1);
		binary_levelorder_helper(tree->right, func, level - 1);
	}
}
/**
 * binary_tree_levelorder - print from level to level for each node
 * @tree: node
 * @func: print function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height;
	int level = 1;

	if (!tree || !func)
		return;

	height = height4levelorder(tree) + 1;
	level = 1;

	while (level <= height)
	{
		binary_levelorder_helper(tree, func, level);
		level++;

	}

}
