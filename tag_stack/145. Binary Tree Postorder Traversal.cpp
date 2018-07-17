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
    /*vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodeStack;
        vector<int> result;
        if(!root)
            return result;
        nodeStack.push(root);
        while(!nodeStack.empty())
        {
            TreeNode* node= nodeStack.top();  
            result.push_back(node->val);
            nodeStack.pop();
            if(node->left)
                nodeStack.push(node->left);
            if(node->right)
                nodeStack.push(node->right);
        }
        reverse(result.begin(),result.end());
        return result;
    }*/

    /*
        Below is Morris Traversal
    */
    void reverseNodes(TreeNode* start,TreeNode* end)
    {
        if(start==end)
            return;
        TreeNode* x = start;
        TreeNode* y = start->right;
        TreeNode* z = nullptr;
        while(x!=end)
        {
            z = y->right;
            y->right = x;
            x = y;
            y = z;
        }
    }
    void reverseAddNodes(TreeNode* start,TreeNode* end,vector<int>& nodes)
    {
        reverseNodes(start,end);
        TreeNode* node = end;
        while(true)
        {
            nodes.push_back(node->val);
            if(node==start)
                break;
            node = node->right;
        }
        reverseNodes(end,start);
    }
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> nodes;
        TreeNode tmp(0);
        tmp.left = root;
        TreeNode* dump = &tmp;
        TreeNode* curNode = dump;
        while(curNode)
        {
            if(curNode->left)
            {
                TreeNode* predecessor = curNode->left;
                while(predecessor->right&&predecessor->right!=curNode)
                    predecessor = predecessor->right;
                if(!predecessor->right)
                {
                    predecessor->right = curNode;
                    curNode = curNode->left;
                }else
                {
                    reverseAddNodes(curNode->left,predecessor,nodes);
                    predecessor->right = nullptr;
                    curNode = curNode->right;
                }
            }else
                curNode = curNode->right;
        }
        return nodes;
    }
};