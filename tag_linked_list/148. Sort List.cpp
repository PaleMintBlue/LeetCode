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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return head;
        //search for mid
        ListNode* mid = head;
        ListNode* tmp = head;
        ListNode* prev = head;
        while(tmp!=nullptr&&tmp->next!=nullptr)
        {
            prev = mid;
            mid = mid->next;
            tmp = tmp->next->next;
        }
        prev->next = nullptr; //cut the linked-list
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(mid);
        return merge(l1,l2);
    }
private:
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
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
