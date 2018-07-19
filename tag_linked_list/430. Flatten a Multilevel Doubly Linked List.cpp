/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node* tail = nullptr;
        helper(head,tail);
        return head;
    }
    
    void helper(Node* head,Node*& tail)
    {
        if(!head)
            return;
        if(head->child)
        {
            Node* temp = head->next;
            head->next = head->child;
            head->child->prev = head;
            head->child = nullptr;
            helper(head->next,tail);
            tail->next = temp;
            if(temp)
                temp->prev = tail;
            helper(temp,tail);
        }else
        {
            tail = head;
            helper(head->next,tail);
        }
    }
};