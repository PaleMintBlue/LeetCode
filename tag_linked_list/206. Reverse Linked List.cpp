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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode* oldNode = head;
        ListNode* newNode = head->next;
        ListNode* tmp = nullptr;
        while(newNode)
        {
            tmp = newNode->next;
            newNode->next = oldNode;
            oldNode = newNode;
            newNode = tmp;
        }
        head->next = nullptr;
        return oldNode;
    }
};