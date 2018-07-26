/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int,int> map;
        return helper(root,sum,0,map);
    }
    int helper(TreeNode* node,int sum,int pre,unordered_map<int,int>& map)
    {
        if(!node)
            return 0;
        node->val += pre;
        int ret = (node->val==sum) + (map.count(node->val-sum)?map[node->val-sum]:0);
        map[node->val]++;
        ret += helper(node->left,sum,node->val,map) + helper(node->right,sum,node->val,map);
        map[node->val]--;
        return ret;
    }
};*/
class Solution
{
public:
    int pathSum(TreeNode* root,int sum)
    {
        if(!root)
            return 0;
        return pathSumFrom(root,sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
    }
private:
    int pathSumFrom(TreeNode* node,int sum)
    {
        if(!node)
            return 0;
        return (node->val==sum?1:0) + pathSumFrom(node->left,sum-node->val) + pathSumFrom(node->right,sum-node->val);
    }
};