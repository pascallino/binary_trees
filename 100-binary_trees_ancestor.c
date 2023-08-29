#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node to find the ancestor
 * @second: a pointer to the second node to find the ancestor
 *
 * Return: pointer to the ancestor node
 *         NULL if there is no ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{

	const binary_tree_t *temp_first = first;
	const binary_tree_t *temp_second = second;

	if (!first || !second)
		return (NULL);

	while (temp_first != temp_second)
	{
		temp_first = (temp_first) ? temp_first->parent : second;
		temp_second = (temp_second) ? temp_second->parent : first;
	}

	return ((binary_tree_t *)temp_first);
}

