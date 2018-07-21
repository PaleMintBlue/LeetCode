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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)
            return vector<double>{};
        queue<TreeNode*> q;
        vector<double> ret;
        q.push(root);
        int current = 1;
        int next = 0;
        long long sum = 0;
        long long count = 0;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            current--;
            sum += node->val;
            count++;
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
                ret.push_back(1.0*sum/count);
                sum = 0;
                count = 0;
            }
        }
        return ret;
    }
};