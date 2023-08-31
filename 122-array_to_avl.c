#include "binary_trees.h"
/**
 * array_to_avl - AVL tree built from an array
 * @array: array to be built from
 * @size: size of the  array
 * Return: root node or NULL
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (!avl_insert(&tree, array[i]))
		{
			return (NULL);
		}
	}
	return (tree);
}
