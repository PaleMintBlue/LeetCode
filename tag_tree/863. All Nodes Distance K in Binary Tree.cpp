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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(!root)
            return {};
        findParent(root);
        dfs(target,K);
        return ans;
    }
    void findParent(TreeNode* node)
    {
        if(!node)
            return;
        if(node->left)
        {
            parent[node->left] = node;
            findParent(node->left);
        }
        if(node->right)
        {
            parent[node->right] = node;
            findParent(node->right);
        }
    }
    void dfs(TreeNode* node,int K)
    {
        if(visited.find(node)!=visited.end())
            return; //visited
        visited.insert(node);
        if(K==0)
        {
            ans.push_back(node->val);
            return;
        }
        if(node->left)
        {
            dfs(node->left,K-1);
        }
        if(node->right)
        {
            dfs(node->right,K-1);
        }
        TreeNode* p = parent[node];
        if(p)
            dfs(p,K-1);
    }
private:
    std::vector<int> ans;
    std::map<TreeNode*,TreeNode*> parent; // son-parent pair
    std::set<TreeNode*> visited;
};