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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(!head) return head;
        ListNode* cur = head;
        ListNode* Pre = new ListNode(-1);
        Pre->next = head;
        ListNode* check;
        ListNode* pre = Pre;
        while(cur){
            int flag = 0;
            check = Pre;
            while(check != cur){
                if( check->val == cur->val ){
                    flag = 1;
                    break;
                }
                else {
                    check = check->next;
                }
            }
            if (flag == 1) cur = cur->next;
            else {
                pre->next = cur;
                cur = cur->next;
                pre = pre->next;
            }
        }
        pre->next = nullptr;
        return head;
    }
};


# 官方题解
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        unordered_set<int> occurred = {head->val};
        ListNode* pos = head;
        // 枚举前驱节点
        while (pos->next != nullptr) {
            // 当前待删除节点
            ListNode* cur = pos->next;
            if (!occurred.count(cur->val)) {
                occurred.insert(cur->val);
                pos = pos->next;
            } else {
                pos->next = pos->next->next;
            }
        }
        pos->next = nullptr;
        return head;
    }
};