/*
 * @Author: Mayc
 * @Date: 2021-01-15 15:22:42
 * @LastEditTime: 2021-01-15 15:22:53
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 32 - II. 从上到下打印二叉树\source_code.cpp
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        queue<TreeNode*> Queue;
        if(root == nullptr) return ans;
        int level = 0;
        int nextprint = 1;
        Queue.push(root);
        while(!Queue.empty()){
            TreeNode* node = Queue.front();
            temp.emplace_back(node->val);
            if(node->left) {
                Queue.push(node->left);
                level++;
            }
            if(node->right){
                Queue.push(node->right);
                level++;
            }
            Queue.pop();
            --nextprint;
            if(nextprint == 0){
                ans.emplace_back(temp);
                temp.clear();
                nextprint = level;
                level = 0;
            }
        }
        return ans;
    }
};