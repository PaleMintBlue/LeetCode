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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return vector<string>{};
        vector<string> ret;
        std::stack<TreeNode*> stk;
        std::stack<std::string> pathStack;
        stk.push(root);
        pathStack.push(to_string(root->val));
        while(!stk.empty())
        {
            auto node = stk.top();
            stk.pop();
            auto currentPath = pathStack.top();
            pathStack.pop();
            if(node->left==nullptr&&node->right==nullptr)
            {
                ret.push_back(currentPath);
                continue;
            }
            if(node->left)
            {
                stk.push(node->left);
                pathStack.push(currentPath+"->"+to_string(node->left->val));
            }
            if(node->right)
            {
                stk.push(node->right);
                pathStack.push(currentPath+"->"+to_string(node->right->val));
            }
        }
        return ret;
    }
};