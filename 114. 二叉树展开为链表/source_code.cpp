/*
 * @Author: Mayc
 * @Date: 2021-01-28 11:47:01
 * @LastEditTime: 2021-01-28 12:08:21
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\114. 二叉树展开为链表\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> l;
        preorderTraversal(root, l);
        int n = l.size();
        for (int i = 1; i < n; i++) {
            TreeNode *prev = l.at(i - 1), *curr = l.at(i);
            prev->left = nullptr;
            prev->right = curr;
        }
    }

    void preorderTraversal(TreeNode* root, vector<TreeNode*> &l) {
        if (root != NULL) {
            l.push_back(root);
            preorderTraversal(root->left, l);
            preorderTraversal(root->right, l);
        }
    }
};

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

    void Flatte(TreeNode* root, TreeNode** Root){
        if( root == nullptr ) return;
        (*Root)->right = new TreeNode(root->val);
        (*Root)->left = nullptr;
        (*Root) = (*Root)->right;
        Flatte(root->left, Root);
        Flatte(root->right, Root);
        return;
    }

    void flatten(TreeNode* root) {
        TreeNode* Root = new TreeNode(-1);
        TreeNode* temp = Root;
        if( !root ) return;
        Flatte(root, &Root);
        root->left = nullptr;
        root->right = temp->right->right;
    }
};

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
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while( cur ){
            if ( cur->left ){
                auto next = cur->left;
                auto prenode = next;
                while( prenode->right ){
                    prenode = prenode->right;
                }
                prenode->right = cur->right;
                cur->left = nullptr;
                cur->right = next;

            }
            cur = cur->right;
        }
    }
};