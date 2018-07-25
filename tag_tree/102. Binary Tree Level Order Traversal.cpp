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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return vector<vector<int>>{};
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        q.push(root);
        int current = 1;
        int next = 0;
        vector<int> currentVector;
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            currentVector.push_back(node->val);
            if(node->left)
            {
                q.push(node->left);
                next++;
            }
            if(node->right)
            {
                q.push(node->right);
                next++;
            }
            current--;
            if(current==0)
            {
                current = next;
                next = 0;
                ret.push_back(currentVector);
                currentVector.clear();
            }
        }
        return ret;
    }
};