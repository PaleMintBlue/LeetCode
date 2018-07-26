/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*class Solution
{
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        if(!root1&&!root2)
            return true;
        if(!root1||!root2)
            return false;
        std::vector<int> left1;
        std::vector<int> left2;
        getLeaf(root1,left1);
        getLeaf(root2,left2);
        if(left1.size()!=left2.size())
            return false;       
        for(int i = 0; i < left1.size(); i++)
        {
            if(left1[i]!=left2[i])
                return false;
        }    
        return true;
    }
    void getLeaf(TreeNode* root,std::vector<int>& vec)
    {
        if(!root)
            return;
        std::stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty())
        {
            auto node = stack.top();
            stack.pop();
            if(!node->left&&!node->right)
            {
                vec.push_back(node->val);
            }
            if(node->right)
            {
                stack.push(node->right);
            }
            if(node->left)
            {
                stack.push(node->left);
            }
        }
    }
};*/
class Solution
{
public:
    bool leafSimilar(TreeNode* root1,TreeNode* root2)
    {
        /*
        * Compare leaf-value node by node
        * much quicker if it is a large Tree.
        */
        std::stack<TreeNode*> s1;
        std::stack<TreeNode*> s2;
        s1.push(root1);
        s2.push(root2);
        while(!s1.empty()&&!s2.empty())
            if(dfs(s1)!=dfs(s2))
                return false;
        return s1.empty()&&s2.empty();
    }
    int dfs(std::stack<TreeNode*>& s)
    {
        while(true)
        {
            auto node = s.top();
            s.pop();
            if(node->right)
                s.push(node->right);
            if(node->left)
                s.push(node->left);
            if(!node->left&&!node->right)
                return node->val;
        }
    }
};