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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return vector<vector<int>>{};
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> temp(size);
            for(int i = 0;i<size;i++)
            {
                auto node = q.front();
                q.pop();
                if(leftToRight)
                    temp[i] = node->val;
                else
                    temp[size-i-1] = node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
    
            }
            leftToRight = !leftToRight;
            ret.push_back(temp);
        }
        return ret;
    }
};