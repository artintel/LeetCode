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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head == nullptr){
            return head;
        }
        ListNode* temp = head;
        ListNode* pre = head;
        while(temp){
            if(temp->val == val && temp == pre){
                temp = temp->next;
                head = temp;
                break;
            }
            else if (temp->val ==val && temp != pre){
                pre->next = temp->next;
                break;
            }
            else if(temp->val != val && temp == pre){
                temp = temp->next;
            }
            else {
                pre = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};