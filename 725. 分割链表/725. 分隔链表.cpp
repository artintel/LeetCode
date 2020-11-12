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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ans;
        while(root){
            ans.emplace_back(root);
            root = root->next;
        }

        if( k == 1 ){
            ans.resize(1);
            return ans;
        }
        int len = ans.size();
        if(k == len) {
            for(int i = 0; i < len; i++){
                ans[i]->next = nullptr;
            }
            return ans;
        }
        if(k > len){
            for(int i = 0; i < len; i++){
                ans[i]->next = nullptr;
            }
            while(k > len){
                ans.emplace_back(nullptr);
                k--;
            }
            return ans;
        }
        int divid = len / k; //记录每一组至少多少个节点
        int divid_mood = len % k;//余多少，就有多少个组需要多增加一个节点
        vector<ListNode*> ans_true;
        int index = 0;//记录节点位置
        ListNode* Temp = ans[index];
        int lens;//记录当前需要有几个节点
        while(k){
            if(divid_mood != 0){
                lens = divid + 1;
                ans_true.emplace_back(Temp);
                ans[index + lens - 1]->next = nullptr;
                index += lens;
                Temp = ans[index];
                divid_mood--;
            }
            else{
                lens = divid;
                ans_true.emplace_back(Temp);
                ans[index + lens - 1]->next = nullptr;
                index += lens;
                if(index < len)
                    Temp = ans[index];
                else break;
            }
            k--;
        }
        return ans_true;
    }
};