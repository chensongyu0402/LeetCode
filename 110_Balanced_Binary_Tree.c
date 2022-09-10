/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int height(struct TreeNode *node)
{
    if(node == NULL)
        return 0;
    int l = height(node->left);
    int r = height(node->right);
    return (l > r ? (l + 1) : (r + 1));
}

bool isBalanced(struct TreeNode* root)
{
    int l,r;
    if(root == NULL)
        return true;
    l = height(root -> left);
    r = height(root -> right);
    if(abs(l - r) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    else
        return false;
}