/**
 * 
 * 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
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
    bool isPalindrome(ListNode* head) {
        vector<int> alist;

        while(head != nullptr)
        {
            alist.emplace_back(head->val);
            head = head->next;
        }

        int j = alist.size() - 1;
        for (int i = 0; i < alist.size()/2; i++)
        {
            if (alist[i] != alist[j])
            {
                return false;
            }
            j--;
        }
        return true;

    }
};