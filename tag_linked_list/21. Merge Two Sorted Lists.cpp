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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode tmp(-1);
        ListNode* pTmp = &tmp;
        while(l1&&l2)
        {
            if(l1->val<l2->val)
            {
                pTmp->next = l1;
                l1 = l1->next;
            }else
            {
                pTmp->next = l2;
                l2 = l2->next;
            }
            pTmp = pTmp->next;
        }
        if(!l1)
            pTmp->next = l2;
        if(!l2)
            pTmp->next = l1;
        return tmp.next;
    }
};