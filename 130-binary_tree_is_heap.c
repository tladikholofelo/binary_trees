#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: If tree is NULL - 0.
 *         Else, return the size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * tree_is_complete - Checks if a tree is complete
 * @tree: Pointer to the root node of the tree
 * @i: Node index
 * @cnodes: Number of nodes
 *
 * Return: If tree is complete - 1.
 *         Otherwise - 0.
 */
int tree_is_complete(const binary_tree_t *tree, int i, int cnodes)
{
	if (tree == NULL)
		return (1);

	if (i >= cnodes)
		return (0);

	return (tree_is_complete(tree->left, (2 * i) + 1, cnodes) &&
		tree_is_complete(tree->right, (2 * i) + 2, cnodes));
}


/**
 * binary_tree_is_complete - Calls tree_is_complete function
 * @tree: Pointer to the root node of the tree
 * Return: If tree is complete - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t cnodes;

	if (tree == NULL)
		return (0);

	cnodes = binary_tree_size(tree);

	return (tree_is_complete(tree, 0, cnodes));
}

/**
 * check_parent - Checks if parent has a greater value than its childs
 * @tree: Pointer to the root node of the tree
 *
 * Return: If parent has a greater value - 1.
 *         Otherwise - 0.
 */
int check_parent(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * binary_tree_is_heap - Checks if an input tree is a Max Binary Heap
 * @tree: Pointer to the root node of the tree
 *
 * Return: If tree is a Max Binary Heap - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_tree_is_complete(tree))
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}
