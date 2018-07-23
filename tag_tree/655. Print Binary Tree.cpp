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
    int getHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        return std::max(getHeight(root->left),getHeight(root->right))+1;
    }
    vector<vector<string>> printTree(TreeNode* root) {
        if(!root)
            return {};
        auto height = getHeight(root);
        auto width = std::pow(2,height)-1;
        std::vector<string> temp(width,"");
        std::vector<std::vector<string>> ret(height,temp);
        fillTable(ret,root,0,0,width-1);
        return ret;
    }
    void fillTable(std::vector<std::vector<std::string>>& ret,TreeNode* root,int depth,int begin,int end)
    {
        if(!root)
            return;
        int mid = begin + ((end-begin)>>1);
        ret[depth][mid] = to_string(root->val);
        fillTable(ret,root->left,depth+1,begin,mid-1);
        fillTable(ret,root->right,depth+1,mid+1,end);
    }
};