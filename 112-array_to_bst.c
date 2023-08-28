#include "binary_trees.h"
/*Function to build a Binary Search Tree from an array*/
/**
 * array_to_bst - array conversio  to bst
 * @array: array to convert
 * @size: size of array
 * Return: Root
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root;
	size_t i;

	if (array == NULL || size == 0)
	{
		return (NULL); /*Return NULL if the array is empty or NULL.*/
	}

	root = NULL; /*Initialize the root of the BST to NULL*/

	for (i = 0; i < size; i++)
	{
		/*Insert each element of the array into the BST*/
		bst_insert(&root, array[i]);
	}

	return (root); /*Return the root of the created BST*/
}
