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
};*/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        while(cur&&cur->val!=key)
        {
            pre = cur;
            if(key<cur->val)
                cur = cur->left;
            else if(key>cur->val)
                cur = cur->right;
        }
        if(!pre)
            return deleteRootNode(cur);
        if(pre->left==cur)
            pre->left = deleteRootNode(cur);
        else
            pre->right = deleteRootNode(cur);
        return root;
    }
private:
    TreeNode* deleteRootNode(TreeNode* root)
    {
        if(!root)
            return nullptr;
        if(!root->left)
            return root->right;
        if(!root->right)
            return root->left;
        TreeNode* next = root->right;
        TreeNode* pre = nullptr;
        for(;next->left;pre = next,next = next->left)
            ;
        next->left = root->left;
        if(root->right!=next)
        {
            pre->left = next->right;
            next->right = root->right;
        }
        return next;
    }
};