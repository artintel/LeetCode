/**
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
    ListNode* revers(ListNode* node){
        ListNode* temp = new ListNode(-1);
        temp->next = nullptr;
        ListNode* cur;
        while(node){
            cur = node->next;
            node->next = temp->next;
            temp->next = node;
            node = cur;
        }
        return temp->next;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* Head = new ListNode(-1);
        Head->next = head;
        int m = 1;
        ListNode* pre = Head;
        ListNode* behind = head;
        ListNode* tail;
        ListNode* cur = head;
        while(cur){
            if(m % k == 0){
                tail = cur->next;
                cur->next = nullptr;
                pre->next = revers(behind);
                behind->next = tail;
                pre = behind;
                behind = pre->next;
                cur = behind;
                m = 1;
            }
            else{
                cur = cur->next;
                m++;
            }
        }
        return Head->next;
    }
};