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
    ListNode* reverseList(ListNode* head) {
        ListNode* Head = new ListNode(-1);
        Head->next = nullptr;
        ListNode* cur = head;
        while(head){
            head = head->next;
            cur->next = Head->next;
            Head->next = cur;
            cur = head;
        }
        return Head->next;
    }
};