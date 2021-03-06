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
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return -1;
        std::set<int,greater<int>> set;
        std::queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty())
        {
            auto node = queue.front();
            queue.pop();
            if(node->left)
                queue.push(node->left);
            if(node->right)
                queue.push(node->right);
            if(set.size()<k)
                set.insert(node->val);
            else
            {
                auto itr = set.begin();
                if(node->val<*itr)
                {
                    set.erase(itr);
                    set.insert(node->val);
                }
            }
        }
        return *set.begin();
    }
};