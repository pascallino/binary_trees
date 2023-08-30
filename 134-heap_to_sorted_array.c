#include "binary_trees.h"

/**
 * binary_tree_size5 - suze of the tree
 * @tree: root node
 * Return: 1 or 0
 */

size_t binary_tree_size5(const binary_tree_t *tree)
{
	int leftSize = 0, rightSize = 0;

	if (tree == NULL)
	{
		return (0); /*If the tree is empty, it has no nodes, so size is 0.*/
	}

	/*Recursively calculate the size of the left and right subtrees*/
	leftSize = binary_tree_size5(tree->left);
	rightSize = binary_tree_size5(tree->right);

	/*Return the total size, which is 1 (for the current node)*/
	/* plus the sizes of the left and right subtrees*/
	return (1 + leftSize + rightSize);



}

/**
 * heap_to_sorted_array - convert max heap to a sorted array
 * @size: size of the heap
 * @heap: heap
 * Return: int
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int extractedRoot = 0;
	int *arr;
	size_t i = 0;


	if (heap == NULL)
	{
		return (NULL);
	}

	*size = binary_tree_size5(heap);
	arr = malloc(sizeof(int) * *size);
	if (!arr)
		return (NULL);
	while (heap)
	{
		extractedRoot = heap_extract(&heap);
		arr[i] = extractedRoot;
		i++;
	}
	return (arr);
}
