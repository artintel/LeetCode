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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode* Head = new ListNode(-1);
        ListNode* Pre = new ListNode(-1);
        Head->next = nullptr;
        ListNode* temp = Head;
        Pre->next = head;
        ListNode* pre = Pre;
        ListNode* cur = head;
        while(cur){
            if(cur->val < x){
                pre->next = cur->next;
                cur->next = temp->next;
                temp->next = cur;
                temp = temp->next;
                cur = pre->next;
            }
            else{
                pre = pre->next;
                cur = cur->next;
            }
        }
        temp->next = Pre->next;
        return Head->next;
    }
};