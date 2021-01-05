/*
 * @Author: Mayc
 * @Date: 2021-01-05 08:43:38
 * @LastEditTime: 2021-01-05 08:44:29
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\101. 对称二叉树\source_code.cpp
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
class Solution {
public:

    bool check(TreeNode* u, TreeNode* v){
        if( !u && !v ) return true;
        if( !u || !v ) return false;
        return u->val == v->val && check(v->left, u->right) && check(v->right, u->left);
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};


// 递归
class Solution {
public:
    bool check(TreeNode *u, TreeNode *v) {
        queue <TreeNode*> q;
        q.push(u); q.push(v);
        while (!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if (!u && !v) continue;
            if ((!u || !v) || (u->val != v->val)) return false;

            q.push(u->left); 
            q.push(v->right);

            q.push(u->right); 
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};