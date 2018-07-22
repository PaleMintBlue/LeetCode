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
    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0;
        helper(root,max);
        return max;
    }
    int helper(TreeNode* root,int& max)
    {
        if(!root)
            return 0;
        int leftVal = helper(root->left,max);
        int rightVal = helper(root->right,max);
        max = std::max(leftVal+rightVal,max);
        return std::max(leftVal,rightVal) + 1;
    }
};