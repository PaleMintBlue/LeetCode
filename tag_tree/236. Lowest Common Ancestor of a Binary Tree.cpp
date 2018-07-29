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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||root==p||root==q)
            return root;
        auto left = lowestCommonAncestor(root->left,p,q);
        auto right = lowestCommonAncestor(root->right,p,q);
        if(left&&right)
            return root;
        else if(!left)
            return right;
        else
            return left;
    }
};*/
class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p,TreeNode* q)
    {
        std::map<TreeNode*,TreeNode*> parent;
        std::stack<TreeNode*> stack;
        parent[root] = nullptr;
        stack.push(root);
        while(!parent.count(p)||!parent.count(q))
        {
            auto node = stack.top();
            stack.pop();
            if(node->left)
            {
                parent[node->left] = node;
                stack.push(node->left);
            }
            if(node->right)
            {
                parent[node->right] = node;
                stack.push(node->right);
            }
        }
        std::set<TreeNode*> ancestors;
        while(p)
        {
            ancestors.insert(p);
            p = parent[p];
        }
        while(ancestors.find(q)==ancestors.end())
        {
            q = parent[q];
        }
        return q;
    }
};