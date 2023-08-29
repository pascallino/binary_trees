#include "binary_trees.h"
bst_t *inorder_successor(bst_t *node);
bst_t *delete(bst_t *root, int value);
/**
 * bst_remove - Removes a node from a Binary Search Tree.
 *
 * @root: A pointer to the root node of the tree where you will remove a node.
 * @value: The value to remove in the tree.
 *
 * Return: A pointer to the new root node of the tree after removing.
 */
bst_t *bst_remove(bst_t *root, int value)
{
    return delete(root, value);
}

/**
 * bst_delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *delete(bst_t *root, int value)
{
    if (root == NULL)
        return root;

    if (value < root->n)
        root->left = delete(root->left, value);
    else if (value > root->n)
        root->right = delete(root->right, value);
    else { // Node with the value to be deleted found
        if (root->left == NULL) {
            bst_t *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            bst_t *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children; find the in-order successor
        bst_t *temp = inorder_successor(root->right);

        // Copy the in-order successor's value to this node
        root->n = temp->n;

        // Recursively delete the in-order successor
        root->right = delete(root->right, temp->n);
    }
    return root;
}

/**
 * inorder_successor - Returns the minimum value node of a binary search tree.
 * @node: A pointer to the root node of the BST.
 *
 * Return: The minimum value node in the BST.
 */
bst_t *inorder_successor(bst_t *node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}

