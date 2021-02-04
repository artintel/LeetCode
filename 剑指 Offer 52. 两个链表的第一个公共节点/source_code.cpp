/*
 * @Author: Mayc
 * @Date: 2021-02-04 13:38:00
 * @LastEditTime: 2021-02-04 13:38:23
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 52. 两个链表的第一个公共节点\source_code.cpp
 * @这是一个漂亮的注释头
 */
/**
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
        ListNode* p = headA;
        ListNode* q = headB;
        while( q != p ){
            q = q ? q->next : headA;
            p = p ? p->next : headB;
        }
        return q;
    }
};