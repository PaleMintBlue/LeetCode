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
    int numComponents(ListNode* head, vector<int>& G) {
        if(!head)
            return 0;
        int listLength = countLength(head);
        map<int,int> mp{};
        for(int i = 0;i<listLength;i++)
            mp[i] = -1;
        for(int i = 0;i<G.size();i++)
            mp[G[i]] = i;
        int cnt = 0;
        ListNode* p = head;
        bool lastFound = false;
        while(p)
        {
            if(mp[p->val]>=0)
            {
                if(!lastFound)
                {
                    cnt++;
                    lastFound = true;
                }
                mp[p->val] = -1;
            }else
                lastFound = false;
            p = p->next;
        }
        return cnt;
    }
private:
    int countLength(ListNode* head)
    {
        int length = 0;
        while(head)
        {
            head = head->next;
            length++;
        }
        return length;
    }
};