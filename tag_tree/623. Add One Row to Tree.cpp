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
};