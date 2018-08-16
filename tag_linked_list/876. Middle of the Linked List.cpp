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
    ListNode* middleNode(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode* walker = head;
        ListNode* runner = head;
        while(runner&&runner->next)
        {
            walker = walker->next;
            runner = runner->next->next;
        }
        return walker;
    }
};