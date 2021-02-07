/*
 * @Author: Mayc
 * @Date: 2021-02-07 15:08:57
 * @LastEditTime: 2021-02-07 15:09:07
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 54. 二叉搜索树的第 K 大节点\source_code.cpp
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
    int index;
    TreeNode* cur;
public:

    void visit( vector<int>& ans, TreeNode* cur, int& count, const int& k ){
        if(cur == nullptr) return;
        visit(ans, cur->left, count, k);
        ans.emplace_back(cur->val);
        if(count == k){
            index = 0;
            count++;
        }
        else if( count > k ){
            index++;
        }
        else count++;
        visit(ans, cur->right, count, k);
    }

    int kthLargest(TreeNode* root, int k) {
        cur = root;
        int count = 1;
        vector<int> ans;
        visit( ans, cur, count, k );
        return ans[index];
    }
};