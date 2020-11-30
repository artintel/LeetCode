class Solution {
    bool dfs(TreeNode* root, ListNode* head){
        //如果head指向空，说明找到了root中的那一条对应的路径
        if(head == nullptr) return true;
        //如果root指向空，说明没找到，返回false
        if(root == nullptr) return false;
        //如果两个节点值不等，也没对，返回false
        if(root->val != head->val) return false;
        //分别从left路径，right路径dfs
        return dfs(root->left, head->next) || dfs(root->right, head->next);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == nullptr) return false;
        //当前节点没有这个路径，就尝试 root->left 或者 root->right路径有没有
        return (dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right));
    }
};