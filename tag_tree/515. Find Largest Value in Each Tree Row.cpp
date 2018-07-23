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
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return vector<int>{};
        vector<int> ret{};
        queue<TreeNode*> q;
        q.push(root);
        int currentMax = std::numeric_limits<int>::min();
        int current = 1;
        int next = 0;
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            currentMax = std::max(currentMax,node->val);
            current--;
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
            if(current==0)
            {
                current = next;
                next = 0;
                ret.push_back(currentMax);
                currentMax = std::numeric_limits<int>::min();
            }
        }
        return ret;
    }
};