/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return head;
        }
        else{
            vector<Node*> ans;
            vector<Node*> ANS;
            Node* temp = head;
            ans.emplace_back(new Node(temp->val, nullptr, nullptr));
            ANS.emplace_back(temp);
            int i = 1;
            temp = temp -> next;
            while(temp){
                ANS.emplace_back(temp);
                ans.emplace_back(new Node(temp->val, nullptr, nullptr));
                ans[i - 1]->next = ans[i];
                i++; 
                temp = temp->next;
            }
            ans[ans.size() - 1]->next = nullptr;

            for(int j = 0; j < ANS.size(); j++){
                if(ANS[j]->random == nullptr){
                    ans[j]->random = nullptr;
                }
                else{
                    vector<Node*>::iterator it = find(ANS.begin(), ANS.end(), ANS[j]->random);
                    int index = distance(ANS.begin(), it);
                    ans[j]->random = ans[index];
                }
            }
            return ans[0];
        }
    }
};