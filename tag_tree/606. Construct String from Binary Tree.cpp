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
    string tree2str(TreeNode* t) {
        if(!t)
            return "";
        string s;
        helper(t,s);
        return s;
    }
    void helper(TreeNode* t,string& s)
    {
        if(!t)
            return;
        s += to_string(t->val);
        if(!t->left&&!t->right)
            return;
        s += '(';
        helper(t->left,s);
        s += ')';
        if(!t->right)
            return;
        s += '(';
        helper(t->right,s);
        s += ')';
    }
};