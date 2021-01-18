/*
 * @Author: Mayc
 * @Date: 2021-01-18 12:41:49
 * @LastEditTime: 2021-01-18 12:57:26
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 36. 二叉搜索树与双向链表\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    void change(Node* root, Node** NodeList) {
        if (root == nullptr) return;
        if (root->left) {
            change(root->left, NodeList);
        }
        root->left = *NodeList;
        if (*NodeList != nullptr) {
            (*NodeList)->right = root;
        }
        *NodeList = root;
        if (root->right) {
            change(root->right, NodeList);
        }
    }
    Node* treeToDoublyList(Node* root) {
        Node* headList = nullptr;
        if (root == nullptr) return root;
        change(root, &headList);
        Node* temp = headList;
        while (temp && temp->left) {
            temp = temp->left;
        }
        temp->left = headList;
        headList->right = temp;
        return temp;
    }
};

class Solution {
public:
    void change(Node* root, queue<Node*>& ans) {
        if(root == nullptr) return;
        if(root->left){
            change(root->left, ans);
        }
        ans.push(root);
        if(root->right){
            change(root->right, ans);
        }
    }
    Node* treeToDoublyList(Node* root) {
        queue<Node*> ans;
        if(root == nullptr) return nullptr;
        change(root, ans);
        Node* temp = ans.front();
        Node* head = temp;
        ans.pop();
        while(!ans.empty()){
            temp->right = ans.front();
            ans.front()->left = temp;
            ans.pop();
            temp = temp->right;
        }
        temp->right = head;
        head->left = temp;

        return head;
    }
};