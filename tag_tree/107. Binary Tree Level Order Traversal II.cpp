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
    void levelOrderBottom(TreeNode* root,vector<vector<int>>& ret,int height)
    {
        if(!root)
            return;
        if (ret.size() <= height)
            ret.push_back(vector<int>());
    
        ret[height].push_back(root->val);
        levelOrderBottom(root->left,ret,height+1);
        levelOrderBottom(root->right,ret,height+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return vector<vector<int>>{};
        vector<vector<int>> ret{};
        levelOrderBottom(root,ret,0);
        reverse(ret.begin(),ret.end());
        return ret;
    }
};