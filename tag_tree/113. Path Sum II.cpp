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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)
            return {};
        std::vector<std::vector<int>> ret;
        std::vector<int> currentPath;
        findPath(root,sum,ret,currentPath);
        return ret;
    }
    void findPath(TreeNode* root,int sum,std::vector<std::vector<int>>& ret,std::vector<int>& currentPath)
    {
        if(!root)
            return;
        currentPath.push_back(root->val);
        if(sum==root->val&&!root->left&&!root->right)
            ret.push_back(currentPath);
        findPath(root->left,sum-root->val,ret,currentPath);
        findPath(root->right,sum-root->val,ret,currentPath);
        currentPath.pop_back();
    }
};