
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
        ListNode *p1, *p2, *p1prev, *p2prev, *newnode;
        int sum, carry = 0;
        
        if (!l1) return (l2);
        if (!l2) return (l1);
        
        p1 = l1;
        p2 = l2;
        
        while (p1 && p2) {
            sum = p1->val + p2->val + carry;
            p1->val = sum % 10;
            carry = sum / 10;
            
            p1prev = p1;
            p2prev = p2;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        if (!p1) {
            p1prev->next = p2prev->next;
        }
        
        p1 = p1prev->next;
        
        while (p1) {
            sum = p1->val + carry;
            p1->val = sum % 10;
            carry = sum / 10;
            p1prev = p1prev->next;
            p1 = p1->next;
        }
        
        if (carry) {
            newnode = new ListNode(carry);
            p1prev->next = newnode;
        }
        
        return (l1);
    }
};