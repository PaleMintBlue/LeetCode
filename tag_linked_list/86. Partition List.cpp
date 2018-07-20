/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return nullptr;
        ListNode smallerList(-1);
        ListNode biggerList(-1);
        ListNode* smaller = &smallerList;
        ListNode* bigger = &biggerList;
        smaller->next = bigger->next = nullptr;
        ListNode prevHead(-1);
        prevHead.next = head;
        ListNode* tmp = &prevHead;
        while(tmp&&tmp->next)
        {
            ListNode* nextNode = tmp->next;
            if(nextNode->val<x)
            {
                smaller->next = nextNode;
                smaller = nextNode;
            }else
            {
                bigger->next = nextNode;
                bigger = nextNode;
            }
            tmp = nextNode;
        }
        smaller->next = biggerList.next;
        bigger->next = nullptr;
        return smallerList.next;
    }
};