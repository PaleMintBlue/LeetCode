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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root)
            return vector<int>{};
        std::unordered_map<int,int> map;
        int maxCount = 0;
        helper(root,maxCount,map);
        std::vector<int> ret;
        for(const auto& pair:map)
        {
            if(pair.second==maxCount)
                ret.push_back(pair.first);
        }
        return ret;
    }
    int helper(TreeNode* root,int& maxCount,std::unordered_map<int,int>& map)
    {
        if(!root)
            return 0;
        auto left = helper(root->left,maxCount,map);
        auto right = helper(root->right,maxCount,map);
        auto sum = left + right + root->val;
        map[sum]++;
        maxCount = std::max(maxCount,map[sum]);
        return sum;
    }
};