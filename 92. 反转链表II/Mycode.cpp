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
    //常规反转
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
            // m == n 说明没有发转，直接返回
            return head;
        }
        //额外开辟一个新的头节点
        ListNode* Pre = new ListNode(-1);
        Pre->next = head;
        ListNode* M = Pre;
        ListNode* N = head;
        //记录M 和 N的节点距离是否满足 m - n 
        int gap = 0;
        int n_cur = 1;
        while(n_cur < n){//检查N节点是否已经到达指定位置
            if(gap < n - m){//检查M节点和N的节点的距离是否满足题设
                gap++;//满足M开始走，不满足M节点原地不动，gap++
            }
            else if (gap == n - m){//满足M开始走，不满足M节点原地不动，gap++
                M = M->next;
            }
            N = N->next;
            n_cur++;
        }
        ListNode* head_m = M->next;//记录需要反转的链表头节点
        ListNode* tail_n = N->next;//记录需要反转的链表最后节点的next节点
        N->next = nullptr;
        M->next = nullptr;
        M->next = revers(head_m);
        head_m->next = tail_n;
        return Pre->next;
    }
};