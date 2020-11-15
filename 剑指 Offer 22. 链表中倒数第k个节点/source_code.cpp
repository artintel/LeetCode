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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int gap = 1;
        ListNode* tail = head;
        ListNode* pre = head;
        while(tail->next){
            if(gap < k){
                tail = tail->next;
                gap++;
            }
            else{
                tail = tail->next;
                pre = pre->next;
            }
        }
        return pre;
    }
};