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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) break;
        }
        if(fast->next == nullptr || fast->next->next == nullptr) return nullptr;
        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};