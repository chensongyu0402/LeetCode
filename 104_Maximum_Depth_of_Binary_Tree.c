/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define max(a,b) (a > b ? a : b)
int maxDepth(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    int ll = maxDepth(root -> left);
    int rl = maxDepth(root -> right);
    return max(ll,rl) + 1;
}