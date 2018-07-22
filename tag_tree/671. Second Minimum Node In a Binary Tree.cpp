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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)
            return -1;
        const int k = 2;
        std::set<int,greater<int>> intSet;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            if(intSet.size()<k)
                intSet.insert(node->val);
            else
            {
                auto itr = intSet.begin();
                
                if(node->val<*itr&&intSet.find(node->val)==intSet.end())
                {
                    intSet.erase(itr);
                    intSet.insert(node->val);
                }
            }
        }
        if(intSet.size()<k)
            return -1;
        auto begin = intSet.begin();
        return *begin;
    }
};