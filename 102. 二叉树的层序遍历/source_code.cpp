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
        queue<TreeNode*> Q;
        if( !root ) return ans;
        Q.push(root);
        int count = 1;
        int next_count = 0;
        while( !Q.empty() ){
            if(count > 0){
                temp.emplace_back(Q.front()->val);
                if(Q.front()->left){
                    next_count++;
                    Q.push(Q.front()->left);
                }
                if(Q.front()->right){
                    next_count++;
                    Q.push(Q.front()->right);
                }
                count--;
                Q.pop();
            }
            if(count == 0) {
                count = next_count;
                ans.push_back(temp);
                next_count = 0;
                temp.clear();
            }
        } 
        return ans;
    }
};