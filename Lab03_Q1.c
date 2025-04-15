// Leetcode 94: Binary Tree Inorder Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void inorder(struct TreeNode *root, int *result, int *returnSize)
{
    // Base Case with empty tree
    if (root == NULL)
        return;

    // NOTE: Traversing Path is Left -> Visit -> Right

    // Recursion through left subtree
    inorder(root->left, result, returnSize);

    // Visit root
    result[(*returnSize)++] = root->val;

    // Recursion through right subtree
    inorder(root->right, result, returnSize);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    // Allocate space for nodes
    int *result = (int *)malloc(sizeof(int) * 2000);
    // Initialize size of the result array
    *returnSize = 0;
    // Start traversing
    inorder(root, result, returnSize);
    // Return the result array containing the inorder traversal
    return result;
}