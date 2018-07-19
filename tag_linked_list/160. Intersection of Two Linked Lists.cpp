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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*ListNode *cur1 = headA, *cur2 = headB;
        while(cur1 != cur2){
            cur1 = cur1?cur1->next:headB;
            cur2 = cur2?cur2->next:headA;
        }
        return cur1;*/
        if(!headA||!headB)
            return nullptr;
        int len1 = countLength(headA);
        int len2 = countLength(headB);
        
        if(len2>len1)
        {
            std::swap(len1,len2);
            std::swap(headA,headB);
        }
        
        int diff = len1-len2;
        while(diff)
        {
            headA = headA->next;
            diff--;
        }
        
        while(headA&&headB&&headA->val!=headB->val)
        {
            headA = headA->next;
            headB = headB->next;
        }
        if(headA&&!headB)
            return nullptr;
        return headA;
    }
    
    int countLength(ListNode* head)
    {
        int length = 0;
        while(head)
        {
            length++;
            head = head->next;
        }
        return length;
    }
    
};