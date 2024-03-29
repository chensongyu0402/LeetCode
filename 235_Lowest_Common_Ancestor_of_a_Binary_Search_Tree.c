/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    if((p -> val < root -> val && q -> val > root -> val) || 
        (p -> val > root -> val && q -> val < root -> val))
            return root;
    if(p -> val == root -> val)
        return root;
    if(q -> val == root -> val)
        return root;
    if(p -> val < root -> val) {
        root = root -> left;
        return lowestCommonAncestor(root,p,q);
    }else {
        root = root -> right;
        return lowestCommonAncestor(root,p,q);
    }
}