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
    int numComponents(ListNode* head, vector<int>& G) {
        if(!head) return 0;
        unordered_set<int> g; //用哈希增加速度
        for(int i : G) g.insert(i);
        int result = 0;//组件个数
        int flag = 0;// 当g.find(head->val)查找成功的时候置为1，当查找失败的时候，检查flag是否为0
        //如果检查发现flag == 0，说明这是G/g的第一个数，result不需要自增1，
        while(head){
            if(g.find(head->val) != g.end()){
                flag = 1;
            }
            else{
                if(flag == 1){
                    result++;
                    flag = 0;
                }
            }
            head = head->next;
        }
        if(flag != 0) result++;

        return result;
    }
};