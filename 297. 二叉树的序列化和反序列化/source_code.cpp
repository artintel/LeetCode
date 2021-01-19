/*
 * @Author: Mayc
 * @Date: 2021-01-19 12:26:33
 * @LastEditTime: 2021-01-19 12:27:06
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\297. 二叉树的序列化和反序列化\source_code.cpp
 * @这是一个漂亮的注释头
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

void _serialize(TreeNode* root, string& s){
        if(!root) {
            s += "&,";
            return;
        }
        s += to_string(root->val);
        s += ",";
        _serialize(root->left, s);
        _serialize(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        if(!root) return s;
        _serialize(root, s);
        return s;
    }

    void _deserialize(TreeNode** root, queue<string>& temp){
        if( temp.empty() ) return;
        string s = temp.front();
        if( s != "&" ){
            *root = new TreeNode(stoi(s));
            temp.pop();
            _deserialize(&(*root)->left, temp);
            _deserialize(&(*root)->right, temp);
        }
        else {
            temp.pop();
            return;
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root;
        int n = data.size();
        if(n == 0) return nullptr;
        int start = 0;
        queue<string> temp;
        string s = "";
        for(char elem : data){
            if( elem != ','){
                if(elem != '&') s += elem;
                else {
                    if( s.size() > 0 ) temp.push(s);
                    temp.push("&");
                    s = "";
                }
            }
            else{
                if( s.size() > 0 ){
                    temp.push(s);
                    s = "";
                }
            }
        }
        _deserialize(&root, temp);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));