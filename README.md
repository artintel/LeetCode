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

## [92. 反转链表 II，暴力求解](https://github.com/artintel/LeetCode/blob/master/92.%20%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8II/Mycode.cpp)

> 先用两个指针通过移动分别找到 m 的前一个位置结点和 n 的当前节点。
>
> 为避免出现在1个节点出现的相应情况，选择`new`了一个头节点，该节点的下一个节点指向 `head`
>
> 在找到对应的两个节点位置后，将该段节点倒置，再连接起来

# [138. 复制带随机指针的链表](https://)

> 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
>
> 要求返回这个链表的 **深拷贝** 
>
> 我们用以一个由 `n` 个节点组成的链表表示输入、输出中的链表。每个节点用一个 `[val, random_index]` 表示
>
> - `val`: 一个表示 `Node.val` 的整数
> - `random_index`: 随机指针指向的节点索引(0~n-1)；如果不指向任何节点，则为 `nullptr`。
>
> ```c++
> 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
> 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
> ```
>
> 我的想法很粗糙，就是新建了两个vector，分别用来按顺序储存原链表和new 新的链表，同时接上next指针，这样需要做的就只有random指针了，那么再通过 `find() 和 distance()` 两个函数来查找到 random 指向的位置，再在new出来的数组中进行链接。 很暴力，当以后有了更好的想法后再更新

