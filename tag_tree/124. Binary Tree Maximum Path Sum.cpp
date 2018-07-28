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
    int maxPathSum(TreeNode* root) {
        int maxVal = std::numeric_limits<int>::min();
        helper(root,maxVal);
        return maxVal;
    }
    int helper(TreeNode* root,int& maxVal)
    {
        if(!root)
            return 0;
        auto left = std::max(helper(root->left,maxVal),0);
        auto right = std::max(helper(root->right,maxVal),0);
        maxVal = std::max(maxVal,left+right+root->val);
        return std::max(left,right)+root->val;
    }
};