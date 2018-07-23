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
    int findBottomLeftValue(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            root = q.front();
            q.pop();
            if(root->right)
                q.push(root->right);
            if(root->left)
                q.push(root->left);
        }
        return root->val;
    }
};*/
class Solution {
public:
    int getHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        return std::max(getHeight(root->left),getHeight(root->right))+1;
    }
    int findBottomLeftValue(TreeNode* root) {
        if(!root)
            return -1;
        auto height = getHeight(root);
        int ret = 0;
        findMax(root,height,ret);
        return ret;
    }
    void findMax(TreeNode* root,int height,int& ret)
    {
        if(!root)
            return;
        if(height==1)
        {
            ret = root->val;
            return;
        }
        findMax(root->right,height-1,ret);
        findMax(root->left,height-1,ret);
    }
};
