#include "binary_trees.h"
size_t binary_tree_sizeh(const binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);
/**
 * binary_tree_sizeh - suze of the tree
 * @tree: root node
 * Return: 1 or 0
 */

size_t binary_tree_sizeh(const binary_tree_t *tree)
{
	int leftSize = 0, rightSize = 0;

	if (tree == NULL)
	{
		return (0); /*If the tree is empty, it has no nodes, so size is 0.*/
	}

	/*Recursively calculate the size of the left and right subtrees*/
	leftSize = binary_tree_sizeh(tree->left);
	rightSize = binary_tree_sizeh(tree->right);

	/*Return the total size, which is 1 (for the current node)*/
	/* plus the sizes of the left and right subtrees*/
	return (1 + leftSize + rightSize);

}
/**
 * binary_tree_node2 - ceate a node
 * @parent: new node
 * @value: node value
 * Return: Node
 */
binary_tree_t *binary_tree_node2(binary_tree_t *parent, int value)
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
/**
 * heap_insert - Inserts a value into a binary max heap.
 *
 * @root: A pointer to the root node of the binary heap.
 * @value: The value to insert into the heap.
 *
 * Return: A pointer to the new root node of the binary heap.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new_node, *current_parent;
	int tree_size, remaining_leaves, subtree_size, mask, level, temp;

	if (!root)
		return (NULL);

	if (!(*root))
		return (*root = binary_tree_node2(NULL, value));

	tree = *root;
	tree_size = binary_tree_sizeh(tree);
	remaining_leaves = tree_size;

	/*Calculate the level and the number of remaining leaves*/
	for (level = 0, subtree_size = 1; remaining_leaves >= subtree_size;
			subtree_size *= 2, level++)
		remaining_leaves -= subtree_size;

	mask = 1 << (level - 1); /*Initialize the mask for traversal*/

	/*Traverse the tree to find the appropriate insertion point*/
	current_parent = tree;
	while (mask != 1)
	{
		current_parent =
			(remaining_leaves & mask) ? current_parent->right : current_parent->left;
		mask >>= 1;
	}

	/*Create a new node and insert it into the heap*/
	new_node = binary_tree_node2(current_parent, value);
	(remaining_leaves & 1) ? (current_parent->right = new_node) :
		(current_parent->left = new_node);

	/*Perform the "bubble-up" operation to maintain the heap property*/
	while (new_node->parent && (new_node->n > new_node->parent->n))
	{
		/*Swap the values of the new node and its parent*/
		temp = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = temp;
		new_node = new_node->parent; /*Move to the parent node*/
	}

	return (new_node); /*Return the new root node*/
}

