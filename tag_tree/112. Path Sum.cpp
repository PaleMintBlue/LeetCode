/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        if(root->val==sum&&!root->left&&!root->right)
            return true;
        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
    }
};*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        std::stack<int> numStack;
        std::stack<TreeNode*> nodeStack;
        numStack.push(root->val);
        nodeStack.push(root);
        while(!nodeStack.empty())
        {
            auto node = nodeStack.top();
            nodeStack.pop();
            auto num = numStack.top();
            numStack.pop();
            if(!node->left&&!node->right&&num==sum)
            {
                return true;
            }else
            {
                if(node->right)
                {
                    nodeStack.push(node->right);
                    numStack.push(node->right->val+num);
                }
                if(node->left)
                {
                    nodeStack.push(node->left);
                    numStack.push(node->left->val+num);
                }
            }
        }
        return false;
    }
};