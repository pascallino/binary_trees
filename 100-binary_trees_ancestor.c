#include "binary_trees.h"


/* Helper function to check if a node is in the subtree*/
/* from the parent of the */
/* first node recursively*/
/**
 * isDescendant - check if  the second node is a decendant of the first nodes
 * parent
 * @root: first node root(s)
 * @node: second node to scan from
 * Return: 1 or 0
 */
int isDescendant(const binary_tree_t *root, const binary_tree_t *node)
{
	if (root == NULL)
	{
		return (0);
	}

	if (root == node)
	{
		return (1);
	}

	return (isDescendant(root->left, node) || isDescendant(root->right, node));
}

/**
 * binary_trees_ancestor - find the anscestor of two nodes
 * @first: first node root(s)
 * @second: second node to scan from
 * Return: anscestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *current;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	current = first;
	while (current != NULL)
	{
		if (isDescendant(current->left, second))
		{
			return ((binary_tree_t *)current);
		} else if (isDescendant(current->right, second))
		{
			return ((binary_tree_t *)current);
		}

		current = current->parent;
	}

	return (NULL); /* No common ancestor found*/
}

