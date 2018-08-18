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
    int longestUnivaluePath(TreeNode* root) {
        int ret = 0;
        helper(root,-1,ret);
        return ret;
    }
    int helper(TreeNode* root,int val,int& ret)
    {
        if(!root)
            return 0;
        auto left = helper(root->left,root->val,ret);
        auto right = helper(root->right,root->val,ret);
        ret = std::max(ret,left+right);
        return root->val==val?std::max(left,right)+1:0;
    }
};