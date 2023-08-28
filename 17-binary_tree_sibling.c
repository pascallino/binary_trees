#include "binary_trees.h"

/**
 * binary_tree_sibling - who is my sibling
 * @node: node to get node sibling
 * Return: node;
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{

	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->right == node)
		return (node->parent->left);

	return (node->parent->right);

}
