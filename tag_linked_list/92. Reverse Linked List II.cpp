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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n)
            return head;
        n -= m;
        ListNode preHead(0);
        preHead.next = head;
        ListNode* begin = &preHead;
        while(--m)
        {
            begin = begin->next;
        }
        ListNode* oldNode = begin->next;
        ListNode* newNode = oldNode->next;
        ListNode* tmp = NULL;
        while(n--)
        {
            tmp = newNode->next;
            newNode->next = oldNode;
            oldNode = newNode;
            newNode = tmp;
        }
        begin->next->next = newNode;
        begin->next = oldNode;
        return preHead.next;
    }
};