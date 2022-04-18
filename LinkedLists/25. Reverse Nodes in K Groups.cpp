/**
 * 
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

进阶：

你可以设计一个只使用常数额外空间的算法来解决此问题吗？
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curtail = head;
        ListNode* curptr = head;
        ListNode* curprev;
        ListNode* curhead = head;
        bool init = true;
        int counter = 0;
        while(curptr != nullptr)
        {
            curprev = curptr;
            curptr = curptr->next;
            counter++;
            if (counter == k)
            {
                curprev->next = nullptr;
                if (init)
                {
                    head = reverseList(head);
                    curtail = curhead;
                    curhead->next = curptr;
                    curhead = curptr;
                    init = false;
                }else{
                    curtail->next  = reverseList(curhead);
                    curtail = curhead;
                    curhead = curptr;
                }
                
                counter = 0;
            }
        }
        curtail->next = curhead;
        return head;
    }

    ListNode* reverseList(ListNode* head)
    {
        ListNode* slow;
        ListNode* mid = head;
        ListNode* fast = head->next;
        while(fast != nullptr)
        {
            
            slow = mid;
            mid = fast;
            fast = fast->next;
            mid->next = slow;
        }
        head->next = nullptr;
        return mid;
    }
};