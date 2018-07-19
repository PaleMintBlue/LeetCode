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
        ListNode* pTmp = head;
        while(pTmp->next)
        {
            if(pTmp->next->val!=pTmp->val)
            {
                pTmp = pTmp->next;
            }
            else
            {
                ListNode* nextNode = pTmp->next;
                pTmp->next = nextNode->next;
            }
        }
        return head;
    }
};