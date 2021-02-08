/*
 * @Author: Mayc
 * @Date: 2021-02-08 11:12:31
 * @LastEditTime: 2021-02-08 11:12:43
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 55 - II. 平衡二叉树\source_code.cpp
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

    bool IsBalanced(TreeNode* root, int& depth){
        if( !root ) {
            depth = 0;
            return true;
        }
        int n_left, n_right;
        if(IsBalanced(root->left, n_left) && IsBalanced(root->right, n_right)){
            int diff = n_left - n_right;
            if( diff <= 1 && diff >= -1){
                depth = 1 + ( n_left > n_right ? n_left : n_right );
                return true;
            }
        }
        return false;
    }

    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return IsBalanced(root, depth);
    }
};