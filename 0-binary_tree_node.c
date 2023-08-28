#include "binary_trees.h"

/**
 * binary_tree_node - ceate a node
 * @parent: new node
 * @value: node value
 * Return: Node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{

	binary_tree_t *newnode = (binary_tree_t *) malloc(sizeof(binary_tree_t));

	if (newnode == NULL)
	{
		return (NULL);
	}
	newnode->parent = parent;
	newnode->n = value;
	newnode->left = NULL;
	newnode->right = NULL;

	return (newnode);




}
