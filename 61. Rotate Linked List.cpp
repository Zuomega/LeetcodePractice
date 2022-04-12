/**
 * 
 * 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)
        {
            return head;
        }
        ListNode* curptr = head;
        int length = 1;
        while(curptr->next != nullptr)
        {
            length++;
            curptr = curptr->next;
        }
        curptr->next = head;
        length = length - (k % length);
        curptr = head;
        while(length > 1)
        {
            length--;
            curptr = curptr->next;

        }
        ListNode* tmpnode = curptr;
        curptr = curptr->next;
        tmpnode->next = nullptr;
        return curptr;
    }
};