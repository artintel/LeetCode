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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int J = 0;
        ListNode* sum;
        ListNode* S = new ListNode(-1);
        ListNode* cur = S;
        while(l1 && l2){
            sum = new ListNode((l1->val + l2->val + J) % 10);
            cur->next = sum;
            cur = sum;
            J = (l1->val + l2->val + J) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            sum = new ListNode((l1->val + J) % 10);
            cur->next = sum;
            cur = sum;
            J = (l1->val + J) / 10;
            l1 = l1->next;
        }

        while(l2){
            sum = new ListNode((l2->val + J) % 10);
            cur->next = sum;
            cur = cur->next;
            J = (l2->val + J) / 10;
            l2 = l2->next;
        }

        if(J != 0){
            sum = new ListNode(J);
            cur->next= sum;
            cur = sum;
        }
        cur->next = nullptr;
        return S->next;
    }
};