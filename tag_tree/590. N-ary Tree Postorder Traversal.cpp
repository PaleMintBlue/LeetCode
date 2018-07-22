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
    vector<int> postorder(Node* root) {
        if(!root)
            return {};
        vector<int> res;
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            Node* temp=stk.top();
            stk.pop();
            res.push_back(temp->val);
            for(int i=0;i<temp->children.size();i++) 
                stk.push(temp->children[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};