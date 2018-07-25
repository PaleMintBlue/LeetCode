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
    vector<int> findMode(TreeNode* root) {
        if(!root)
            return {};
        vector<int> ret;
        int maxCount = 0;
        int currentCount = 0;
        int prevVal = 0;
        helper(root,ret,maxCount,currentCount,prevVal);
        return ret;
    }
    void helper(TreeNode* root,std::vector<int>& ret,int& maxCount,int& currentCount,int& prevVal)
    {
        if(!root)
            return;
        helper(root->left,ret,maxCount,currentCount,prevVal);
        if(root->val==prevVal)
        {
            currentCount++;
        }else
        {
            prevVal = root->val;
            currentCount = 1;
        }
        if(currentCount>maxCount)
        {
            maxCount = currentCount;
            ret = {root->val};
        }else if(currentCount==maxCount)
        {
            ret.push_back(root->val);
        }
        helper(root->right,ret,maxCount,currentCount,prevVal);
    }
};