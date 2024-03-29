/**

给你一个链表的头节点 head ，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

如果链表中存在环 ，则返回 true 。 否则，返回 false 。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/linked-list/jbex5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL)
        {
            return false;
        }
        ListNode * slowptr = head;
        ListNode * fastptr = head;

        while(true){
            if (fastptr ->next != NULL){
                fastptr = fastptr->next;
                if (fastptr == slowptr){
                    return true;
                }else if (fastptr-> next != NULL)
                {
                    fastptr = fastptr->next;
                    if(fastptr == slowptr)
                    {
                        return true;
                    }
                }
            }
            if (slowptr->next != NULL){
                slowptr = slowptr->next;
            }
            if (slowptr->next == NULL || fastptr->next == NULL)
            {
                return false;
            }
        }
        
    }
};