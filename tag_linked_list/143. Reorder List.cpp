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
    void reorderList(ListNode* head) {
        if(!head||!head->next)
            return;
        ListNode* walker = head;
        ListNode* runner = head;
        while(runner->next&&runner->next->next)
        {
            walker = walker->next;
            runner = runner->next->next;
        }
        walker->next = reverseList(walker->next);
        ListNode* tmp1 = head;
        ListNode* tmp2 = walker->next;
        while(tmp1!=walker)
        {
            ListNode* nextTmp1 = tmp1->next;
            ListNode* nextTmp2 = tmp2->next;
            tmp1->next = tmp2;
            tmp2->next = nextTmp1;
            tmp1 = nextTmp1;
            tmp2 = nextTmp2;
        }
        tmp1->next = tmp2;
    }
    ListNode* reverseList(ListNode* head)
    {
        if(!head||!head->next)
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