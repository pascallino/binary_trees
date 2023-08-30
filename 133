#include "binary_trees.h"
void heapify_down(heap_t *root);
heap_t *find_last_node(heap_t *root);
/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 *
 * @root: A double pointer to the root node of the heap.
 *
 * Return: The value stored in the root node,
 * or 0 if the heap is empty or fails.
 */
int heap_extract(heap_t **root)
{
	int extracted_value;
	heap_t *last_node;

	if (!*root)
		return (0);

	extracted_value = (*root)->n;

	if (!(*root)->left)
	{
		extracted_value = (*root)->n;
		free(*root);
		*root = NULL;
		return (extracted_value);
	}

	/*Find the last level-order node*/
	last_node = find_last_node(*root);

	/*Replace root value with last node's value*/
	(*root)->n = last_node->n;

	/*Remove the last node*/
	if (last_node->parent)
	{
		if (last_node->parent->left == last_node)
			last_node->parent->left = NULL;
		else
			last_node->parent->right = NULL;
	}
	else
	{
		/*If the last node is the root, set the root to NULL*/
		*root = NULL;
	}

	free(last_node);

	/*Rebuild the heap to maintain the Max Binary Heap property*/
	heapify_down(*root);

	return (extracted_value);
}

/**
 * find_last_node - Finds the last level-order node in a binary tree.
 *
 * @root: A pointer to the root node of the tree.
 *
 * Return: A pointer to the last level-order node.
 */
heap_t *find_last_node(heap_t *root)
{
	heap_t *last_node;

	if (root == NULL)
		return (NULL);

	last_node = NULL;

	/*Perform a level-order traversal to find the last node*/
	for (; root; root = root->left)
	{
		if (root->left)
			last_node = root->left;
		if (root->right)
			last_node = root->right;
	}

	return (last_node);
}

/**
 * heapify_down - Restores the Max Binary Heap
 * property by moving down the tree.
 *
 * @root: A pointer to the root node of the tree.
 */
void heapify_down(heap_t *root)
{
	int temp;
	heap_t *largest = root;
	heap_t *left = root->left;
	heap_t *right = root->right;

	if (left && left->n > largest->n)
		largest = left;

	if (right && right->n > largest->n)
		largest = right;

	if (largest != root)
	{
		temp = root->n;
		root->n = largest->n;
		largest->n = temp;
		heapify_down(largest);
	}
}

