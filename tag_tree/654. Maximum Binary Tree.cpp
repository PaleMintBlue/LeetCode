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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty())
            return nullptr;
        return constructMaximumBinaryTree(nums,0,nums.size()-1);
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums,int left,int right)
    {
        if(left>right)
            return nullptr;
        int max = std::numeric_limits<int>::min();
        int index = -1;
        for(int i = left;i<=right;i++)
        {
            if(nums[i]>max)
            {
                max = nums[i];
                index = i;
            }
        }
        TreeNode* node = new TreeNode(max);
        node->left = constructMaximumBinaryTree(nums,left,index-1);
        node->right = constructMaximumBinaryTree(nums,index+1,right);
        return node;
    }
};