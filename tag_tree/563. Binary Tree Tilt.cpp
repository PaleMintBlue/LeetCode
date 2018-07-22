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
    int findTilt(TreeNode* root) {
        int ret = 0;
        helper(root,ret);
        return ret;
    }
    int helper(TreeNode* root,int& ret)
    {
        if(!root)
            return 0;
        int leftVal = helper(root->left,ret);
        int rightVal = helper(root->right,ret);
        ret += std::abs(leftVal-rightVal);
        return leftVal + rightVal + root->val;
    }
};