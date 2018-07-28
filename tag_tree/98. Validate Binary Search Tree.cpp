/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root,std::numeric_limits<long>::min(),std::numeric_limits<long>::max());
    }
    bool helper(TreeNode* root,long min,long max)
    {
        if(!root)
            return true;
        if(root->val<=min||root->val>=max)
            return false;
        return helper(root->left,min,root->val)&&helper(root->right,root->val,max);
    }
};*/
class Solution
{
public:
    bool isValidBST(TreeNode* root)
    {
        TreeNode* pre = nullptr;
        return helper(root,pre);
    }
    bool helper(TreeNode* root,TreeNode*& pre)
    {
        if(!root)
            return true;
        bool left = helper(root->left,pre);
        if(!left)
            return false;
        if(pre&&pre->val>=root->val)
            return false;
        pre = root;
        bool right = helper(root->right,pre);
        return right;
    }
};