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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* followA = headA;
        ListNode* followB = headB;
        while(followB != followA){
            followA ? followA = followA->next : followA = headB;
            followB ? followB = followB->next : followB = headA;
        }
        return followB;
    }
};