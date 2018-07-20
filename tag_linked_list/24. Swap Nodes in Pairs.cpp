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
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode dummy(-1);
        dummy.next = head;
        
        ListNode* tmp = &dummy;
        ListNode* one = nullptr;
        ListNode* two = nullptr;
        while(tmp->next&&tmp->next->next)
        {
            one = tmp->next;
            two = tmp->next->next;
            one->next = two->next;
            two->next = one;
            tmp->next = two;
            tmp = one;
        }
        return dummy.next;
    }
};