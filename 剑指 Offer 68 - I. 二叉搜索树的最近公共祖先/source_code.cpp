/*
 * @Author: Mayc
 * @Date: 2021-02-22 16:38:07
 * @LastEditTime: 2021-02-22 16:38:40
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 68 - I. 二叉搜索树的最近公共祖先\source_code.cpp
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( root->val >= p->val && root->val <= q->val || root->val <= p->val && root->val >= q->val ) return root;
        else if( root->val < p->val && root->va l < q->val ){
            return lowestCommonAncestor(root->right, p, q);
        }
        else return lowestCommonAncestor(root->left, p, q);

    }
};