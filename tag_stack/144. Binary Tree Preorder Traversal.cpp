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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root)
            return ret;
        TreeNode* p = root;
        std::stack<TreeNode*> stack;
        while(p||!stack.empty())
        {
            while(p)
            {
                ret.push_back(p->val);
                stack.push(p);
                p = p->left;
            }
            if(!stack.empty())
            {
                p = stack.top();
                stack.pop();
                p = p->right;
            }
        }
        return ret;
    }
};