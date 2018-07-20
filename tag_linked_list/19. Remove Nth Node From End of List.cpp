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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head, * q = head;
        
        while(n--)
        {
            if(!p)
                return head;
            p = p->next;
        }
        if(p == nullptr) 
            return head->next; 
        while(p->next){
            q= q->next;
            p = p-> next;
        }
        q->next = q->next->next;
        return head;
    }
};