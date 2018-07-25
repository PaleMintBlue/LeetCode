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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        TreeNode* left = root;
        TreeNode* right = root;
        int height = 0;
        while(right)
        {
            left = left->left;
            right = right->right;
            height++;
        }
        if(left==nullptr)
            return (1<<height)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};