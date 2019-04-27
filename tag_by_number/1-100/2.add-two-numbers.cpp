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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int toAdd = 0;
        ListNode* head = new ListNode(-1);
        ListNode* p = head;
        while(l1 || l2 || toAdd)
        {
        	int val1 = l1?l1->val:0;
        	int val2 = l2?l2->val:0;
        	int next = val1 + val2 + toAdd;
        	toAdd = next/10;
        	ListNode* newNode = new ListNode(next%10);
        	p->next = newNode;
        	p = p->next;
        	l1 = l1?l1->next:nullptr;
        	l2 = l2?l2->next:nullptr;
        }
        return head->next;
    }
};
