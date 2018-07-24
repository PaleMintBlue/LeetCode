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
    int rob(TreeNode* root) {
        int withMe = 0, withoutMe = 0;
        rob(root,withMe,withoutMe);
        return max(withMe,withoutMe);
    }
    void rob(TreeNode* root,int& withMe,int& withoutMe)
    {
        int withMeL = 0, withoutMeL = 0;
        int withMeR = 0, withoutMeR = 0;
        if(!root)
            return;
        rob(root->left,withMeL,withoutMeL);
        rob(root->right,withMeR,withoutMeR);
        withMe = root->val + withoutMeL + withoutMeR;
        withoutMe = max(withMeL,withoutMeL) + max(withMeR,withoutMeR);
    }
};