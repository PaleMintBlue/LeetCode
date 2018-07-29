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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1)
        {
            auto newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }else if(d==0)
        {
            auto newRoot = new TreeNode(v);
            newRoot->right = root;
            return newRoot;
        }
        if(!root)
            return nullptr;
        if(d==2)
        {
            root->left = addOneRow(root->left,v,1);
            root->right = addOneRow(root->right,v,0);
            return root;
        }else if(d>2)
        {
            root->left = addOneRow(root->left,v,d-1);
            root->right = addOneRow(root->right,v,d-1);
            return root;
        }
        return nullptr;
    }
};*/
class Solution
{
public:
    TreeNode* addOneRow(TreeNode* root,int v,int d)
    {
        if(!root)
            return nullptr;
        if(d==1)
        {
            auto newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            if(--d==0)
                return root;
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                auto node = q.front();
                q.pop();
                if(d==1)
                {
                    auto left = new TreeNode(v);
                    auto right = new TreeNode(v);
                    left->left = node->left;
                    right->right = node->right;
                    node->left = left;
                    node->right = right;
                }else
                {
                    if(node->left)
                        q.push(node->left);
                    if(node->right)
                        q.push(node->right);
                }
            }
        }
        return root;
    }
};