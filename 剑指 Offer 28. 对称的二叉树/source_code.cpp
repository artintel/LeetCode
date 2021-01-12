/*
 * @Author: Mayc
 * @Date: 2021-01-12 10:30:35
 * @LastEditTime: 2021-01-12 10:30:41
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 28. 对称的二叉树\source_code.cpp
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
    bool Symmetric(TreeNode* a, TreeNode* b){
        if(!a && !b) return true;
        if(!a || !b) return false;
        return (a->val == b->val) && Symmetric(a->left, b->right) && Symmetric(a->right, b->left);
    }
    bool isSymmetric(TreeNode* root) {
        return Symmetric(root, root);
    }
};