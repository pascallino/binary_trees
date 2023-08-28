#include "binary_trees.h"
bst_t *bst_search(const bst_t *tree, int value);
/* Function to insert a value into a Binary Search Tree*/
/**
 * bst_search - bst insertion of tree nodes let/right
 * @tree: current root node
 * @value: node data
 * Return: inserted node
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	const bst_t *current;

	if (tree == NULL)
	{
		/*If the tree is empty, return null*/
		return (NULL);
	}

	/*Traverse the tree to find the appropriate location for the new value*/
	current = tree;
	while (current != NULL)
	{
		if (value < current->n)
		{
			/*Go to the left subtree if the value is less*/
			if (current->left == NULL)
			{
				/*Insert the new node here*/
				;
			}
			current = current->left;
		}
		else if (value > current->n)
		{
			/*Go to the right subtree if the value is greater*/
			if (current->right == NULL)
			{
				/*Insert the new node here*/
				;
			}
			current = current->right;
		}
		else
		{
			/*Value already exists in the tree, ignore it*/
			return ((bst_t *)current);
		}
	}

	/*This should not be reached, but return NULL on failure*/
	return (NULL);
}
