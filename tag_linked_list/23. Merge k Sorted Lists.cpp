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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        while(lists.size()>1)
        {
            lists.push_back(mergeCore(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    ListNode* mergeCore(ListNode* l1,ListNode* l2)
    {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        if(l1->val<=l2->val)
        {
            l1->next = mergeCore(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next = mergeCore(l2->next,l1);
            return l2;
        }
    }
};