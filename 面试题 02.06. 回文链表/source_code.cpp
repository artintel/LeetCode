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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        ListNode* Pre = new ListNode(-1);
        Pre->next = head;
        ListNode* fast = Pre;
        ListNode* mid = Pre;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            mid = mid->next;
        }
        fast = fast->next ? mid->next->next : mid->next;
        mid->next = nullptr;
        stack<int> ans;
        while(head){
            ans.push(head->val);
            head = head->next;
        }
        while(!ans.empty()){
            if (ans.top() != fast->val) break;
            ans.pop();
            fast = fast->next;
        }
        return ans.empty() ? true : false;
    }
};