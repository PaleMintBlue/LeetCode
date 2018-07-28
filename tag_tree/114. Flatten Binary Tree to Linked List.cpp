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
    void flatten(TreeNode* root) {
        TreeNode* tail = nullptr;
        flatten(root,tail);
    }
    void flatten(TreeNode* root,TreeNode*& tail)
    {
        if(!root)
            return;
        flatten(root->right,tail);
        flatten(root->left,tail);
        root->right = tail;
        root->left = nullptr;
        tail = root;
    }
};*/
class Solution
{
public:
    void flatten(TreeNode* root)
    {
        if(!root)
            return;
        TreeNode* cur = root;
        while(cur)
        {
            if(cur->left)
            {
                TreeNode* left = cur->left;
                while(left->right)
                    left = left->right;
                left->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};