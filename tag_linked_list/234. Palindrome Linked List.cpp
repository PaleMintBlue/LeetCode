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
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)
            return true;
        ListNode* mid = head;
        ListNode* faster = head;
        while(faster->next&&faster->next->next)
        {
            mid = mid->next;
            faster = faster->next->next;
        }
        mid->next = reverse(mid->next);
        mid = mid->next;
        while(mid)
        {
            if(head->val!=mid->val)
                return false;
            head = head->next;
            mid = mid->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head)
    {
        if(!head)
            return nullptr;
        ListNode* oldNode = head;
        ListNode* newNode = oldNode->next;
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