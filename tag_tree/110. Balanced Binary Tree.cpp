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
    bool isBalanced(TreeNode* root) {
        int level = 0;
        return isBalanced(root,level);
    }
    bool isBalanced(TreeNode* root,int& level)
    {
        if(root==nullptr)
        {
            level = 0;
            return true;
        }        
        int left;
        int right;
        if(isBalanced(root->left,left)&&isBalanced(root->right,right))
        {
            int diff = left-right;
            if(diff<=1&&diff>=-1)
            {
                level = std::max(left,right)+1;
                return true;
            }
            return false;
        }
        return false;
    }
};
