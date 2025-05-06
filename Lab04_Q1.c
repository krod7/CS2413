// Leetcode Problem 101: Symmetric Tree
/*
Given the root of a binary tree,
check whether it is a mirror of itself
(i.e., symmetric around its center).
*/

/*
Create helper function
See if the left and right subtrees are mirror images of each other
*/
bool isMirror(struct TreeNode *t1, struct TreeNode *t2)
{
    // If both nodes are NULL, they are symmetric
    if (t1 == NULL && t2 == NULL)
        return true;

    // If only one is NULL, the structure is not symmetric
    if (t1 == NULL || t2 == NULL)
        return false;

    // Check if values in subtrees are the same and mirrored too
    return (t1->val == t2->val)
           // LST of t1 with RST of t2
           && isMirror(t1->left, t2->right)
           // RST of t1 with LST of t2
           && isMirror(t1->right, t2->left);
}

// Main Function
bool isSymmetric(struct TreeNode *root)
{
    // Empty tree is symmetric
    if (root == NULL)
        return true;
    // Call isMirror function to compare the subtrees
    return isMirror(root->left, root->right);
}