/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)
            return nullptr;
        if(!hasOne(root))
            return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        return root;
    }
    
    bool hasOne(TreeNode* root)
    {
        if(!root)
            return false;
        if(root->val==1)
            return true;
         return hasOne(root->left)||hasOne(root->right);
    }
};