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
    ListNode* insertionSortList(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode helper(-1);
        helper.next = nullptr;
        ListNode* cur = head;
        ListNode* prev = &helper;
        ListNode* next = nullptr;
        while(cur)
        {
            next = cur->next;
            while(prev->next&&prev->next->val<cur->val)
            {
                prev = prev->next;
            }
            cur->next = prev->next;
            prev->next = cur;
            prev = &helper;
            cur = next;
        }
        return helper.next;
    }
};