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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        sumOfLeftLeaves(root,sum);
        return sum;
    }
    void sumOfLeftLeaves(TreeNode* root,int& sum)
    {
        if(!root)
            return;
        if(root->left)
        {
            auto node = root->left;
            if(!node->left&&!node->right)
                sum += node->val;
        }
        sumOfLeftLeaves(root->left,sum);
        sumOfLeftLeaves(root->right,sum);
    }
};