# LeetCode
## [1367.二叉树中的列表](https://github.com/artintel/LeetCode/blob/master/1367.%E4%BA%8C%E5%8F%89%E6%A0%91%E4%B8%AD%E7%9A%84%E5%88%97%E8%A1%A8/main.cpp)
> 考虑当前root节点和head的节点情况
> 枚举二叉树中的每个节点为起点往下的路径是否有与链表相匹配的路径。 
> 链表已经全部匹配完，匹配成功，返回 `true`
> 二叉树访问到了空节点，匹配失败，返回 `false`
> 当前匹配的二叉树上节点的值与链表节点的值不相等，匹配失败，返回 `false`
> 前三种情况都不满足，说明匹配成功了一部分，我们需要继续递归匹配，如 `dfs(root->left, head->next)`
> 匹配函数确定了，从根节点开始，如果当前节点匹配成功就直接返回 `true` ，否则继续找它的左儿子和右儿子是否满足，也就是代码中的 `dfs(root,head) || isSubPath(head,root->left) || isSubPath(head,root->right)` ，然后不断的递归调用。

> 参考自：
> 作者：LeetCode-Solution
> 链接：https://leetcode-cn.com/problems/linked-list-in-binary-tree/solution/er-cha-shu-zhong-de-lie-biao-by-leetcode-solution/
> 来源：力扣（LeetCode）
> 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。