/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count =  0;
        while(curr&&count!=k)
        {
            curr = curr->next;
            count++;
        }
        if(count==k)
        {
            curr = reverseKGroup(curr,k);
            while(count-- > 0)
            {
                ListNode* tmp = head->next;
                head->next = curr;
                curr = head;
                head = tmp;
            }
            head = curr;
        }
        return head;
    }
};*/
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==nullptr||k==1) return head;
        int num=0;
        ListNode dummy(-1);
        ListNode *preheader = &dummy;
        preheader->next = head;
        ListNode *cur = preheader, *nex, *pre = preheader;
        while(cur = cur->next) 
            num++;
        while(num>=k) {
            cur = pre->next;
            nex = cur->next;
            for(int i=1;i<k;++i) {
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            pre = cur;
            num-=k;
        }
        return preheader->next;
    }
};