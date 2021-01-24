/*
 * @Author: Mayc
 * @Date: 2021-01-24 11:06:58
 * @LastEditTime: 2021-01-24 11:08:09
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\226. 翻转二叉树\source_code.cpp
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
// 递归 1
class Solution {
public:
    void trace_back(TreeNode* root){
        if(!root) return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        if(root->left){
            trace_back(root->left);
        }
        if(root->right){
            trace_back(root->right);
        }
        return;
    }

    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        trace_back(root);
        return root;
    }
};

// 递归 2
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        invertTree(root->left);
        invertTree(root->right);
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
};