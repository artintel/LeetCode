/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void dfs(Node* head, queue<Node*>& ans){
        if(head == nullptr) return;
        ans.push(head);
        dfs(head->child, ans);
        dfs(head->next, ans);
    }
    Node* flatten(Node* head) {
        if(head == nullptr) return head;
        queue<Node*> ans;
        dfs(head, ans);
        Node* temp = nullptr;
        Node* Head = ans.front();
        while(!ans.empty()){
            temp = ans.front();
            ans.pop();
            if(ans.empty()) break;
            else{
                temp->next = ans.front();
                ans.front()->prev = temp;
                temp->child = nullptr;
            }
        }
        temp->next = nullptr;
        temp->child = nullptr;
        return Head;
    }
};