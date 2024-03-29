#include "binary_trees.h"
#include <limits.h>

/**
 * check_if_BST - recursive helper to binary_tree_is_bst
 * @tree: tree to check for BST
 * @prev: pointer to int, passed "by reference" to update during recursion
 * Return: 1 valid if `tree` is valid BST, or 0 if not or `tree` is NULL
 */
int check_if_BST(const binary_tree_t *tree, int *prev)
{
	if (tree)
	{
		if (!check_if_BST(tree->left, prev))
			return (0);

		if (tree->n <= *prev)
			return (0);

		*prev = tree->n;

		return (check_if_BST(tree->right, prev));
	}
	return (1);
}

/**
 * binary_tree_is_bst - uses recursive helper to test is binary tree is binary
 * search tree: left subtree of each node only has values less than node,
 * right subtree of each node only has values greater than node, tree is a
 * BST at each node, and no values appear twice
 * @tree: tree to check for BST
 * Return: 1 valid if `tree` is valid BST, or 0 if not or `tree` is NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev = INT_MIN;

	if (!tree)
		return (0);

	return (check_if_BST(tree, &prev));
}