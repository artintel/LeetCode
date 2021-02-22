/*
 * @Author: Mayc
 * @Date: 2021-02-22 15:50:27
 * @LastEditTime: 2021-02-22 15:59:06
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 68 - II. 二叉树的最近公共祖先\source_code.cpp
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
    TreeNode* ans;
    bool dfs( TreeNode* root, TreeNode* p, TreeNode* q ){
        if( root == nullptr ) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))){
            ans = root;
        }
        return lson || rson || ( root->val == p->val || root->val == q->val );
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};

class Solution {
public:
    unordered_map<int, TreeNode*> order;
    unordered_map<int, bool> vis;
    void dfs( TreeNode* root){
        if( root == nullptr ) return;
        if( root->left ){
            order[root->left->val] = root;
            dfs(root->left);
        }
        if( root->right ){
            order[root->right->val] = root;
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( root == nullptr ) return nullptr;
        order[root->val] = nullptr;
        dfs(root);
        while( p ){
            vis[p->val] = true;
            p = order[p->val];
        }
        while( q ){
            if(vis[q->val] == true) return q;
            q = order[q->val];
        }
        return nullptr;
    }
};
