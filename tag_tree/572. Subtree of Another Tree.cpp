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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!t)
            return true;
        if(!s)
            return false;
        if(s->val==t->val&&isSameTree(s,t))
            return true;
        else if(isSubtree(s->left,t)||isSubtree(s->right,t))
            return true;
        return false;
    }
    bool isSameTree(TreeNode* s,TreeNode* t)
    {
        if(!s&&!t)
            return true;
        if(!s||!t)
            return false;
        return s->val==t->val&&isSameTree(s->left,t->left)&&isSameTree(s->right,t->right);
    }
};