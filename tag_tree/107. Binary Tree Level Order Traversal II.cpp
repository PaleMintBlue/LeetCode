/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
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
};*/
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        if(!root)
            return {};
        std::queue<TreeNode*> queue;
        queue.push(root);
        std::vector<std::vector<int>> ret;
        while(!queue.empty())
        {
            std::vector<int> tmp;
            int size = queue.size();
            for(int i = 0; i < size;i++)
            {
                auto node = queue.front();
                queue.pop();
                tmp.push_back(node->val);
                if(node->left)
                    queue.push(node->left);
                if(node->right)
                    queue.push(node->right);
            }
            ret.push_back(tmp);
        }
        std::reverse(ret.begin(),ret.end());
        return ret;
    }
};