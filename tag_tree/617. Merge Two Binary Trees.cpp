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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t2==nullptr)
            return t1;
        if(t1==nullptr)
            return t2;
        TreeNode* head = t1;
        head->val += t2->val;
        head->left = mergeTrees(t1->left,t2->left);
        head->right = mergeTrees(t1->right,t2->right);
        return head;
    }
};