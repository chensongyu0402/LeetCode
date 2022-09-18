/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define max(a,b) (a > b ? a : b)
int len(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    int ll = len(root -> left);
    int rl = len(root -> right);
    return max(ll,rl) + 1;
}
int diameterOfBinaryTree(struct TreeNode *root)
{
    if(root == NULL)
        return 0;
    int ll = diameterOfBinaryTree(root -> left);
    int rl = diameterOfBinaryTree(root -> right);
    int l = len(root -> left) + len(root -> right);
    int max1 = max(ll,rl);
    int res = max(max1,l);
    return res;
}