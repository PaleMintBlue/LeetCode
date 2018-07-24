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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return helper(root).second;    
    }
    std::pair<int,TreeNode*> helper(TreeNode* root)
    {
        if(!root)
        {
            return {0,nullptr};
        }
        auto left = helper(root->left);
        auto right = helper(root->right);
        return {std::max(left.first,right.first)+1,left.first==right.first?root:(left.first>right.first?left.second:right.second)};
    }
    
};