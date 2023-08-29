#include "binary_trees.h"
/**
 * binary_tree_insert_left - assign the newnode to the left side
 * of the parent
 * @parent: root
 * @value: int
 * Return: node
 */
/* Function to insert a node as the right child of another node */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	if (!parent)
		return (NULL);

	newnode = binary_tree_node(parent, value);
	if (newnode == NULL)
	{
		return (NULL); /*Return NULL if parent is NULL (invalid operation)*/
	}


	/*If parent already has a right child, move it*/
	/*to the right of the new node*/
	if (parent->left != NULL)
	{
		newnode->left = parent->left;
		parent->left->parent = newnode;
	}

	/* set the new node as the right child of the parent*/
	parent->left = newnode;

	return (newnode);
}
