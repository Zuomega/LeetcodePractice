/**
 *给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
  
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr|| head->next == nullptr) return head;
        ListNode* curnode = head->next;
        head->next = nullptr;
        ListNode* tmpnode;

        while(curnode != nullptr)
        {
            tmpnode = curnode->next;

            curnode->next = head;
            head = curnode;
            curnode = tmpnode;
            
        }    
        return head;
    }
};