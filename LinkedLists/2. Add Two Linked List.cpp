/**
 * 
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/linked-list/fv6w7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* tmpptr = l1;

        int tmp;
        int addi = 0;

        while(ptr1 != nullptr &&  ptr2 != nullptr)
        {
            tmp = ptr1->val + ptr2->val + addi;
            if (tmp > 9)
            {
                ptr1->val = tmp - 10;
                addi = 1;
            }else{
                ptr1->val = tmp;
                addi = 0;
            }
            tmpptr = ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        if (ptr2 != nullptr)
        {
            tmpptr->next = ptr2;
            ptr1 = ptr2;
        }

        while(ptr1 != nullptr)
        {
            tmp = ptr1->val + addi;
            if (tmp > 9)
            {
                ptr1->val = tmp - 10;
                addi = 1;
            }else{
                ptr1->val = tmp;
                addi = 0;
            }
            tmpptr = ptr1;
            ptr1 = ptr1->next;
        }

        if (addi != 0)
        {
            ListNode* newnode = new ListNode(addi);
            tmpptr->next = newnode;
        }

        return l1;
    }

    
};