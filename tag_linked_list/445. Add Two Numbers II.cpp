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
        std::stack<int> stk1;
        std::stack<int> stk2;
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        while(tmp1)
        {
            stk1.push(tmp1->val);
            tmp1 = tmp1->next;
        }
        while(tmp2)
        {
            stk2.push(tmp2->val);
            tmp2 = tmp2->next;
        }
        
        int sum = 0;
        ListNode* head = new ListNode(0);
        head->next = nullptr;
        while(!stk1.empty()||!stk2.empty())
        {
            if(!stk1.empty())
            {
                sum += stk1.top();
                stk1.pop();
            }
            if(!stk2.empty())
            {
                sum += stk2.top();
                stk2.pop();
            }
            head->val = sum%10;
            ListNode* newNode = new ListNode(sum/10);
            newNode->next = head;
            head = newNode;
            sum /= 10;
        }
        return head->val==0?head->next:head;
    }
};