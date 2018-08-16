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
/*
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return nullptr;
        std::stack<Node*> stack;
        stack.push(head);
        Node dummy(-1,nullptr,head,nullptr);
        Node* pre = &dummy;
        while(!stack.empty())
        {
            auto node = stack.top();
            stack.pop();
            pre->next = node;
            node->prev = pre;
            
            if(node->next)
            {
                stack.push(node->next);
                node->next = nullptr;
            }
            if(node->child)
            {
                stack.push(node->child);
                node->child = nullptr;
            }
            pre = node;
        }
        dummy.next->prev = nullptr;
        return dummy.next;
    }
};*/
class Solution {
public:
    Node* flatten(Node* head)
    {
        if(!head)
            return head;
        std::stack<Node*> stack;
        Node* p = head;
        while(p->next || !stack.empty()||p->child)
        {
            if(!p->next&&!stack.empty())
            {
                auto node = stack.top();
                stack.pop();
                node->prev = p;
                p->next = node;
            }
            if(p->child)
            {
                if(p->next)
                    stack.push(p->next);
                p->next = p->child;
                p->next->prev = p;
                p->child = nullptr;
            }
            p = p->next;
        }
        return head;
    }
    /*
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
    }*/
};