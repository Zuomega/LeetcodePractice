/**

给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。

图示两个链表在节点 c1 开始相交：



题目数据 保证 整个链式结构中不存在环。

注意，函数返回结果后，链表必须 保持其原始结构 。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/linked-list/jjbj2/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //a=(n-1)(b+c)+c
        ListNode* ptra = headA;
        ListNode* ptrb = headB;

        ListNode* endnodea = NULL;
        ListNode* endnodeb = NULL;

        while(ptra != ptrb)
        {
           if(ptra -> next == NULL)
           {
               if (endnodea == NULL) 
               {
                   endnodea = ptra;
                   ptra = headB;
               }else{
                   return NULL;
               }
           }else{
               ptra = ptra->next;
           }
           if (ptrb -> next == NULL)
           {
               if (endnodeb == NULL)
               { 
                   endnodeb = ptrb;
                   ptrb = headA;
               }else{
                   return NULL;
               }
           }else{
               ptrb = ptrb->next;
           }
        }
        return ptra;
    }

    
};