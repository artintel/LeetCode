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
    int kthToLast(ListNode* head, int k) {
        ListNode* tail = head;
        ListNode* pre = head;
        while(tail){
            if(k-- > 0){
                tail = tail->next;
            }
            else{
                tail = tail->next;
                pre = pre->next;
            }
        }
        return pre->val;
    }
};