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
    ListNode* revers(ListNode* node){
        ListNode* Head = new ListNode(-1);
        Head->next = nullptr;
        ListNode* temp;
        while(node){
            temp = node->next;
            node->next = Head->next;
            Head->next = node;
            node = temp;
        }
        return Head->next;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n){
            return head;
        }
        ListNode* Pre = new ListNode(-1);
        Pre->next = head;
        ListNode* M = Pre;
        ListNode* N = head;
        int gap = 0;
        int n_cur = 1;
        while(n_cur < n){
            if(gap < n - m){
                gap++;
            }
            else if (gap == n - m){
                M = M->next;
            }
            N = N->next;
            n_cur++;
        }
        ListNode* head_m = M->next;
        ListNode* tail_n = N->next;
        N->next = nullptr;
        M->next = nullptr;
        M->next = revers(head_m);
        head_m->next = tail_n;
        return Pre->next;
    }
};