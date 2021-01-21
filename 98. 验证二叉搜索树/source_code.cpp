/*
 * @Author: Mayc
 * @Date: 2021-01-21 08:49:56
 * @LastEditTime: 2021-01-21 08:50:05
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\98. 验证二叉搜索树\source_code.cpp
 * @这是一个漂亮的注释头
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool inorder(TreeNode* root, int& MAX, int& flag){
        if(!root) return true;
        if(root->left) {
            if(!inorder(root->left, MAX, flag)) return false;
        }
        if(flag == 0){
            MAX = root->val;
            flag = 1;
        }
        else if(flag == 1){
            if( root->val <= MAX ) return false;
            else MAX = root->val;
        }
        if(root->right){
            if(!inorder(root->right, MAX, flag)) return false;
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {
        int MAX, flag = 0;
        if(!root || (!root->left && !root->right)) return true;
        return inorder(root, MAX, flag);
    }
};