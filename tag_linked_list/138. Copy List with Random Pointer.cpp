/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return nullptr;
        //Step1
        RandomListNode *iter = head,*next;
        while(iter)
        {
            next = iter->next;
            RandomListNode* copy = new RandomListNode(iter->label);
            iter->next = copy;
            copy->next = next;
            iter = next;
        }
        //Step2
        iter = head;
        while(iter)
        {
            if(iter->random)
                iter->next->random = iter->random->next;
            iter = iter->next->next;
        }
        //Step3
        iter = head;
        RandomListNode helper(0);
        RandomListNode* pseudoHead = &helper;
        RandomListNode* copy;
        RandomListNode* copyIter = pseudoHead;
        while(iter)
        {
            next = iter->next->next;
            copy = iter->next;
            copyIter->next = copy;
            copyIter = copy;
            iter->next = next;
            iter = next;
        }
        return pseudoHead->next;
    }
};