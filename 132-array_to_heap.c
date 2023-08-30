#include "binary_trees.h"
/**
 * array_to_heap - function to use array to build heap from
 * @array: array
 * @size: size of the array
 * Return: node or NULL
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t index = 0;
	heap_t *root = NULL;

	while (index < size)
	{
		heap_insert(&root, array[index]);
		index++;
	}
	return (root);
}
