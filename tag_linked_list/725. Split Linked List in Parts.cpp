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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ret(k,nullptr);
        if(!root)
            return ret;
        int totalLength = countLength(root);
        int parts = totalLength/k;
        int remainder = totalLength%k;
        ListNode* prev = nullptr;
        ListNode* node = root;
        for(int i = 0;node&&i < k;i++,remainder--)
        {
            ret[i] = node;
            for(int j = 0;j<parts+(remainder>0);j++)
            {
                prev = node;
                node = node->next;
            }
            prev->next = nullptr;
        }
        return ret;
    }
    
private:
    int countLength(ListNode* root)
    {
        int ret = 0;
        while(root)
        {
            ret++;
            root = root->next;
        }
        return ret;
    }
};