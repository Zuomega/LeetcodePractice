/**
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
        {
            return list2;
        }else if(list2 == nullptr)
        {
            return list1;
        }
        ListNode* dummy = new ListNode();
        dummy->next = list1;
        ListNode* ptr1 = list1;
        ListNode* ptr1prev = dummy;
        ListNode* ptr2 = list2;
        while(ptr1 != nullptr && ptr2 != nullptr)
        {
            if (ptr1->val > ptr2->val)
            {
                ListNode* tmpnode = ptr2->next;
                ptr1prev->next = ptr2;
                ptr1prev = ptr2;
                ptr2->next = ptr1;
                ptr2 = tmpnode;
            }else{
                ptr1 = ptr1->next;
                ptr1prev = ptr1prev->next;
            }
        }
        if (ptr2 != nullptr)
        {
            ptr1prev->next = ptr2;
        }

        return dummy->next;
    }
};