#include "binary_trees.h"
/**
 * create_avl -  Recusrsive dunction to create an AVL from a sorted array
 * @rootnode: Root to be created
 * @array: pointer to the first element of the array
 * @start: Index of the first element of the current subarray
 * @end: Index of the last element in the current subarray
 * Return: Pointer to the root node of the created AVL tree.
 */
avl_t *create_avl(binary_tree_t *rootnode, int *array, int start, int end)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = (avl_t *)binary_tree_node(rootnode, array[mid]);

	if (!root)
		return (NULL);

	root->left = create_avl((binary_tree_t *)root, array, start, mid - 1);
	root->right = create_avl((binary_tree_t *)root, array, mid + 1, end);

	return (root);
}
/**
 * sorted_array_to_avl - Builds an avl from a sorted array
 * @array: pointer to the first element of the array
 * @size: array size
 * Return: Pointer to the root node of the created AVL tree.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	binary_tree_t *root = NULL;

	if (!array || size == 0)
		return (NULL);

	return (create_avl(root, array, 0, (int)(size - 1)));
}
