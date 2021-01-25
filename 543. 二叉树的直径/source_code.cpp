/*
 * @Author: Mayc
 * @Date: 2021-01-25 13:24:45
 * @LastEditTime: 2021-01-25 13:24:55
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\543. 二叉树的直径\source_code.cpp
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
private:
    int ans;
    int depth(TreeNode* root){
        if(!root) return 0;
        int L = depth(root->left);
        int R = depth(root->right);
        ans = max(ans, L + R + 1);
        return max(L, R) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
};