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
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return head;
        ListNode* walker = head;
        ListNode* runner = head;
        ListNode* finder = head;
        bool isCircle = false;
        while(runner->next&&runner->next->next)
        {
            walker = walker->next;
            runner = runner->next->next;
            if(walker==runner)
            {
                isCircle = true;
                break;
            }
        }
        if(!isCircle)
            return NULL;
        else{
            ListNode* firstNode = head;
            while(firstNode!=walker)
            {
                firstNode = firstNode->next;
                walker = walker->next;
            }
            return firstNode;
        }
    }
};