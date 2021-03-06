/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        int max = 0;
        return helper(root);
    }
    int helper(Node* root)
    {
        if(!root)
            return 0;
        int max = 0;
        for(auto node:root->children)
        {
            max = std::max(max,helper(node));
        }
        return max+1;
    }
};