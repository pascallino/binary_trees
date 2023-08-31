#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <stddef.h>
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
int binary_tree_is_leaf(const binary_tree_t *node);
void binary_tree_print(const binary_tree_t *tree);
void binary_tree_delete(binary_tree_t *tree);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(binary_tree_t *root, void(*func)(int));
void binary_tree_inorder(binary_tree_t *root, void (*func)(int));
void binary_tree_postorder(binary_tree_t *root, void (*func)(int));
size_t binary_tree_height(binary_tree_t *root);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int is_treeFull(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
int isPerfectBinaryTree(const binary_tree_t *root, int depth, int level);
size_t tree_height(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second);
int isDescendant(const binary_tree_t *root, const binary_tree_t *node);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
size_t height4levelorder(const binary_tree_t *root);
void binary_levelorder_helper(const binary_tree_t *tree,
		void (*func)(int), size_t level);
int binary_tree_is_complete(const binary_tree_t *tree);
int isComplete(const binary_tree_t *tree, int i, int n);
size_t size4completebinary(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
int isBSTHelper(const binary_tree_t *root, int min, int max);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);
bst_t *findMinNode(bst_t *node);
bst_t *bst_min_val(bst_t *root);
int binary_tree_is_avl(const binary_tree_t *tree);
int binary_tree_is_heap(const binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);
heap_t *array_to_heap(int *array, size_t size);
int heap_extract(heap_t **root);
int *heap_to_sorted_array(heap_t *heap, size_t *size);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *avl_remove(avl_t *root, int value);

#endif
