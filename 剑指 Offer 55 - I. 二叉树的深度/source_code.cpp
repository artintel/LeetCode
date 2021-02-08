/*
 * @Author: Mayc
 * @Date: 2021-02-08 10:46:58
 * @LastEditTime: 2021-02-08 10:51:05
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 55 - I. 二叉树的深度\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if( !root ) return 0;
        int nleft = 1 + maxDepth(root->left);
        int nright = 1 + maxDepth(root->right);
        return nleft > nright ? nleft : nright;
    }
};

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

    void dfs(int& max, int& cur, TreeNode* root){
        if( !root ) return;
        cur += 1;
        max = cur > max ? cur : max;
        dfs(max, cur, root->left);
        dfs(max, cur, root->right);
        cur -= 1;
    }

    int maxDepth(TreeNode* root) {
        if( !root ) return 0;
        int max = 1;
        int cur = 0;
        dfs(max, cur, root);
        return max;
    }
};