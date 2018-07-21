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
    bool findTarget(TreeNode* root, int k) {
        std::set<int> record;
        return find(root,record,k);
    }
    bool find(TreeNode* root,std::set<int>& record,int k)
    {
        if(root==nullptr)
            return false;
        if(record.find(k-root->val)!=record.end())
            return true;
        record.insert(root->val);
        return find(root->left,record,k)||find(root->right,record,k);
    }
};