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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        vector<int> ret;
        std::queue<std::pair<TreeNode*,int>> queue;
        queue.push({root,0});
        while(!queue.empty())
        {
            auto node = queue.front();
            queue.pop();
            if(ret.size()==node.second)
            {
                ret.push_back(node.first->val);
            }else
                ret[node.second] = node.first->val;
            if(node.first->left)
                queue.push({node.first->left,node.second+1});
            if(node.first->right)
                queue.push({node.first->right,node.second+1});
        }
        return ret;
    }
};