#include "binary_trees.h"
heap_t *find_last_node(heap_t *root);
heap_t *find_max_child(heap_t *node);
void heapify(heap_t *root);
/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 *
 * @root: A double pointer to the root node of heap.
 *
 * Return: The value stored in the root node.
 */
int heap_extract(heap_t **root)
{
	int value = 0;
	heap_t *last_node;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	if (!(*root)->left)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last_node = find_last_node(*root);
	(*root)->n = last_node->n;

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	free(last_node);
	heapify(*root);

	return (value);
}

/**
 * find_last_node - Finds the last node in a Max Binary Heap.
 *
 * @root: A pointer to the root node of the heap.
 *
 * Return: The last node in the heap.
 */
heap_t *find_last_node(heap_t *root)
{
	heap_t *last_node = root;

	while (last_node->left || last_node->right)
	{
		if (last_node->right)
			last_node = last_node->right;
		else
			last_node = last_node->left;
	}

	return (last_node);
}

/**
 * heapify - Maintains the max heap property after root extraction.
 *
 * @root: A pointer to the root node of the heap.
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *max_child;

	while (1)
	{
		max_child = find_max_child(root);

		if (!max_child || max_child->n <= root->n)
			break;

		value = root->n;
		root->n = max_child->n;
		max_child->n = value;

		root = max_child;
	}
}

/**
 * find_max_child - Finds the maximum child node of a tree.
 *
 * @node: A pointer to the root node of the tree.
 *
 * Return: The maximum child node.
 */
heap_t *find_max_child(heap_t *node)
{
	heap_t *left_child, *right_child;

	left_child = node->left;
	right_child = node->right;

	if (!left_child && !right_child)
		return (NULL);

	if (!right_child || left_child->n >= right_child->n)
		return (left_child);

	return (right_child);
}

