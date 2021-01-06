/*
 * @Author: Mayc
 * @Date: 2021-01-06 09:22:26
 * @LastEditTime: 2021-01-06 09:22:36
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\104. 二叉树的最大深度\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int max = 0;
        int temp = 0;
        if(!root) return 0;
        dfs(root, max, temp);
        return max;
    }
    void dfs(TreeNode* root, int& depth, int& temp){
        temp++;
        depth = max(depth,  temp);
        if(root->left) dfs(root->left, depth, temp);
        if(root->right) dfs(root->right, depth, temp);
        temp--;
    }
};