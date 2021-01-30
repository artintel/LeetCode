/*
 * @Author: Mayc
 * @Date: 2021-01-30 11:42:11
 * @LastEditTime: 2021-01-30 11:42:22
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\236. 二叉树的最近公共祖先\source_code.cpp
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
    unordered_map<int, TreeNode*> order;
    unordered_map<int, bool> vis;
    void dfs(TreeNode* root){
        if( !root ) return;
        if(root->left){
            order[root->left->val] = root;
            dfs(root->left);
        }
        if(root->right){
            order[root->right->val] = root;
            dfs(root->right);
        }
        return;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( !root ) return nullptr;
        order[root->val] = nullptr;
        dfs(root);
        while( p ){
            vis[p->val] = true;
            p = order[p->val];
        }
        while( q ){
            if( vis[q->val] == true ) return q;
            q = order[q->val];
        }
        return nullptr;
        
         
    }
};