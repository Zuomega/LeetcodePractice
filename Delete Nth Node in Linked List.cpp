/**
 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n == 0)
        {
            return head;
        }

        ListNode* fast = head;
        ListNode* slow = nullptr;
        ListNode* slowprev = nullptr;
        int counter = 0;
        while(fast != nullptr){
            if(slow != nullptr)
            {
                slowprev = slow;
                slow = slow->next;
            }
            fast = fast->next;
            counter++;
            if (counter == n )
            {
                slow = head;
            }
          
            
        }
        if(counter < n )
        {
            return head;
        }
        if(slow != nullptr)
        {
            return deleteNode(slow,  slowprev, head);
        }
        return head;
    }
    ListNode* deleteNode(ListNode* dnode, ListNode* prevnode, ListNode* head)
    {
        if (dnode->next != nullptr)
        {
            ListNode* tmpnode = dnode;
            if( prevnode == nullptr)
            {
                head = dnode->next;
            }else{
                prevnode->next = dnode->next;
            }
            delete tmpnode;
        }else{
            ListNode* tmpnode = dnode;
            if( prevnode == nullptr)
            {
                head = dnode->next;
            }else{
                prevnode->next = dnode->next;
            }
            delete tmpnode;
        }
        return head;
    }
};