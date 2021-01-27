/*
 * @Author: Mayc
 * @Date: 2021-01-27 13:36:12
 * @LastEditTime: 2021-01-27 13:36:20
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\105. 从前序与中序遍历构造二叉树\source_code.cpp
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
private: unordered_map<int, int> index;
public:

    TreeNode* combine( const vector<int>& preorder, const vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right ){
        if( pre_left > pre_right ) return nullptr;
        int root_index = pre_left;
        int root_left = index[preorder[root_index]];
        int gap = root_left - in_left;
        TreeNode* root = new TreeNode(preorder[root_index]);
        root->left = combine(preorder, inorder, pre_left + 1, pre_left + gap, in_left, root_left - 1);
        root->right = combine(preorder, inorder, pre_left + gap + 1, pre_right, root_left + 1, in_right );
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0; i < n; i++){
            index[inorder[i]] = i;
        }
        return combine( preorder, inorder, 0, n - 1, 0, n - 1 );
    }
};
