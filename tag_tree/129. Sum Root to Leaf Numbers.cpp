/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        int total = 0;
        queue<TreeNode*> q;
        queue<int> sumq;
        q.push(root);
        sumq.push(root->val);
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            auto val = sumq.front();
            sumq.pop();
            if(node->left==nullptr&&node->right==nullptr)
                total += val;
            else
            {
                if(node->left)
                {
                    q.push(node->left);
                    sumq.push(10*val+node->left->val);
                }
                if(node->right)
                {
                    q.push(node->right);
                    sumq.push(10*val+node->right->val);
                }
            }
        }
        return total;
    }
};*/
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        return helper(root,0);
    }
    int helper(TreeNode* root,int sum)
    {
        if(!root)
            return 0;
        sum = sum*10 + root->val;
        if(!root->left&&!root->right)
            return sum;
        return helper(root->left,sum) + helper(root->right,sum);
    }
};