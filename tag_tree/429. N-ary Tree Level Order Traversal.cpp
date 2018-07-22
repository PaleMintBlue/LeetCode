/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
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
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
        std::queue<Node*> queue;
        queue.push(root);
        vector<vector<int>> ret;
        int curr = 1;
        int next = 0;
        vector<int> temp;
        while(!queue.empty())
        {
            auto node = queue.front();
            queue.pop();
            curr--;
            temp.push_back(node->val);
            for(auto subnode:node->children)
            {
                queue.push(subnode);
                next++;
            }
            if(curr==0)
            {
                curr = next;
                next = 0;
                ret.push_back(temp);
                temp.clear();
            }
        }
        return ret;
    }
};