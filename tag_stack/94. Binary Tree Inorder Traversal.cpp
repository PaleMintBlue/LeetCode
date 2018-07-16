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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root)
            return ret;
        stack<TreeNode*> stack;
        TreeNode* p = root;
        while(p||!stack.empty())
        {
            while(p)
            {
                stack.push(p);
                p = p->left;
            }
            if(!stack.empty())
            {
                p = stack.top();
                stack.pop();
                ret.push_back(p->val);
                p = p->right;
            }
        }
        return ret;
    }
};