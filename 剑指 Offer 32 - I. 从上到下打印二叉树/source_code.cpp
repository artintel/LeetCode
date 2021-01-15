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
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> Queue;
        vector<int> ans;
        if(!root) return ans;
        Queue.push(root);
        while(!Queue.empty()){
            TreeNode* temp = Queue.front();
            Queue.pop();
            if(temp->left) Queue.push(temp->left);
            if(temp->right) Queue.push(temp->right);
            ans.emplace_back(temp->val);
        }
        return ans;
    }
};