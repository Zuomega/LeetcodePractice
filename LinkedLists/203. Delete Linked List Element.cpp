/**
 * @brief 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 * 
 */
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = head;
        ListNode* prev = new ListNode(0, head);
        while(cur != nullptr)
        {
            if (cur->val == val)
            {
                cur = deletenode(cur, prev, head);
            }
            if (cur ->next == nullptr)
            {
                break;
            }
            prev = cur;
            cur = cur->next;
            
        }
        return head;
    }

    ListNode* deletenode(ListNode* cur, ListNode* prev, ListNode*& head)
    {
        if (prev->next == head)
        {
            head = cur->next;
        }
        ListNode* tmpnode = cur;
        prev->next = cur->next;
        cur = prev;
        delete tmpnode;
        return cur;      
    }
};