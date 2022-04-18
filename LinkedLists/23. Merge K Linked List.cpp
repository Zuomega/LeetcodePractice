/**
 * 
 * 给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
        {
            return nullptr;
        }
        int k = lists.size();
        ListNode* curmin;
        int curentry;
        for (int j = 0; j<k; j++)
        {
            if (lists[j] != nullptr)
            {
               curmin = lists[j]; 
               curentry = j;
               break;
            }
            if (j == k-1)
            {
                if (lists[j] == nullptr)
                {
                    return nullptr;
                }
            }
        } 
        ListNode* newhead = new ListNode(0);
        ListNode* newtail = newhead;    
       

        bool isEmpty = true;
        while(true)
        {
            for (int i=0; i<k; i++)
            {
                if (lists[i] == nullptr)
                {
                    continue;
                }
                isEmpty = false;
                if(curmin->val > (lists[i]->val))
                {
                    curmin = lists[i];
                    curentry = i;
                }
            }

            if (isEmpty)
            {
                break;
            }
            newtail->next = curmin;
            newtail = newtail->next;
            lists[curentry] = lists[curentry]->next;
            for (int j = 0; j<k; j++)
            {
                if (lists[j] != nullptr)
                {
                    curmin = lists[j];
                    curentry = j; 
                    break;
                }
            
            }
            isEmpty = true;
        }
        return newhead->next;
    }
};