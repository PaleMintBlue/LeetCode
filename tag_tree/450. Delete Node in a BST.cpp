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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return nullptr;
        if(root->val==key)
        {
            if(!root->right)
                return root->left;
            else
            {
                auto rightNode = root->right;
                while(rightNode->left)
                {
                    rightNode = rightNode->left;
                }
                std::swap(root->val,rightNode->val);
            }
        }
        root->left = deleteNode(root->left,key);
        root->right = deleteNode(root->right,key);
        return root;
    }
};