// Leetcode 144: Binary Tree Preorder Traversal

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

void preorder(struct TreeNode *root, int *result, int *returnSize)
{
    // Base Case with empty tree
    if (root == NULL)
        return;

    // NOTE: Traversing Path is Visit -> Left -> Right

    // Visit root
    result[(*returnSize)++] = root->val;

    // Recursion through subtrees
    // Visit left subtree
    preorder(root->left, result, returnSize);

    // Visit right subtree
    preorder(root->right, result, returnSize);
}

int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
    // Allocate space for nodes
    int *result = (int *)malloc(sizeof(int) * 2000);
    // Initialize size of the result array
    *returnSize = 0;
    // Start traversing
    preorder(root, result, returnSize);
    // Return the result array containing the preorder traversal
    return result;
}