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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode helper(0);
        helper.next = head;
        ListNode* prev = &helper;
        ListNode* cur = head;
        while(cur)
        {
            while(cur->next&&cur->val==cur->next->val)
            {
                cur = cur->next;
            }
            if(prev->next==cur)
            {
                prev = prev->next;
            }else
            {
                prev->next = cur->next;
            }
            cur = cur->next;
        }
        return helper.next;
    }
};