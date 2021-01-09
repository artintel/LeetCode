/*
 * @Author: Mayc
 * @Date: 2021-01-09 17:57:07
 * @LastEditTime: 2021-01-09 17:57:21
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\206. 反转链表\source_code.cpp
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
    ListNode* dfs( ListNode* head ){
        if( head->next == nullptr ){
            return head;
        }
        dfs(head->next)->next = head;
        head->next = nullptr;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr ) return head;
        ListNode* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        dfs(head);
        return temp;
    }
};