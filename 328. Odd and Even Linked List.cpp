/**
 * @brief 给定单链表的头节点 head ，将所有索引为奇数的节点和索引为偶数的节点分别组合在一起，然后返回重新排序的列表。

        第一个节点的索引被认为是 奇数 ， 第二个节点的索引为 偶数 ，以此类推。

        请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。

        你必须在 O(1) 的额外空间复杂度和 O(n) 的时间复杂度下解决这个问题。

        作者：力扣 (LeetCode)
        链接：https://leetcode-cn.com/leetbook/read/linked-list/fe0kj/
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* fast = head->next;
        ListNode* slow = head;
        ListNode* mid = fast;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow->next = fast->next;
            fast->next = slow->next->next;
            slow->next->next = mid;
            fast = fast->next;
            slow = slow->next;
        }
        return head;
    }
};