# 官方分治法：
class Solution {
public:
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr; aPtr = aPtr->next;
            } else {
                tail->next = bPtr; bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }

    ListNode* merge(vector <ListNode*> &lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/he-bing-kge-pai-xu-lian-biao-by-leetcode-solutio-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

# 自己的方法
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
        ListNode* merge(ListNode* list_Node, ListNode* ans) {
            ListNode* Pre = new ListNode();
            ListNode* cur = Pre;
            while (list_Node && ans) {
                if (list_Node->val < ans->val) {
                    cur->next = list_Node;
                    cur = cur->next;
                    list_Node = list_Node->next;
                }
                else {
                    cur->next = ans;
                    cur = cur->next;
                    ans = ans->next;
                }
            }
            if (list_Node == nullptr) {
                cur->next = ans;
            }
            else cur->next = list_Node;
            return Pre->next;
        }

        ListNode* merges(vector<ListNode*>& lists, int l, int r) {
            if (l == r) return lists[l];
            if (l > r) return nullptr;
            int mid = (l + r) >> 1;
            return merge(merges(lists, l, mid), merges(lists, mid + 1, r));
        }

        ListNode* mergeKLists(vector<ListNode*>& lists) {
            return merges(lists, 0, lists.size() - 1);
        }
};