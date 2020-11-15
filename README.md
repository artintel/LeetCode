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

## [138. 复制带随机指针的链表](https://github.com/artintel/LeetCode/blob/master/138.%20%E5%A4%8D%E5%88%B6%E5%B8%A6%E9%9A%8F%E6%9C%BA%E6%8C%87%E9%92%88%E7%9A%84%E9%93%BE%E8%A1%A8/138source_code.cpp)

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

## [725. 分隔链表](https://github.com/artintel/LeetCode/blob/master/725.%20%E5%88%86%E9%9A%94%E9%93%BE%E8%A1%A8/725.%20%E5%88%86%E9%9A%94%E9%93%BE%E8%A1%A8.cpp)

> 给定一个头结点为 root 的链表, 编写一个函数以将链表分隔为 k 个连续的部分。
>
> 每部分的长度应该尽可能的相等: 任意两部分的长度差距不能超过 1，也就是说可能有些部分为 null。
>
> 这k个部分应该按照在链表中出现的顺序进行输出，并且排在前面的部分的长度应该大于或等于后面的长度。
>
> 返回一个符合上述规则的链表的列表。
>
> 举例： 1->2->3->4, k = 5 // 5 结果 [ [1], [2], [3], [4], null ]
>

> 重点在于怎么分配这个数量 --> k 代表一共需要分成多少组，len 代表链表一共有多少个节点
>
> 先考虑简单的情况
>
> 1.  当 `k == len`, 说明每一组刚好一个节点，直接用 `vector<ListNode*> ans` 接收节点，需要注意的是，每个节点的 `next` 需要记得 ->nullptr
> 2.  当 `k > len`, 说明在 `k == len` 的基础上，后续需要扩张 `k - len` 个空间，并置为 `nullptr`
> 3. 当 `k == 1`, 我的代码写法应为已经在之前就已经放进了`ans`，所以直接 `ans.resize(1);` 即可
> 4. 当 `k < len`:
>    1. 首先需要知道每组有多少节点 用 `divid = len / k;` 接收
>    2. 然后就是需要知道有多少组需要添加额外的一个节点，因为任意两组之间的结点数量差距不能超过1，那么用 `divid_mood = len % k;`
>    3. 然后就和上面的操作基本差不多了，需要注意的也就是注意每一组的最后一个结点的 `node->next = nullptr;`
>    4. 最后 `return`

> 写法很不美，事情太多，暂时就不去细扣进阶的操作和细化了。

## [817. 链表组件](https://github.com/artintel/LeetCode/blob/master/817.%20%E9%93%BE%E8%A1%A8%E7%BB%84%E4%BB%B6/source_code.cpp)

> 给定链表头结点 head，该链表上的每个结点都有一个 唯一的整型值 。
>
> 同时给定列表 G，该列表是上述链表中整型值的一个子集。
>
> 返回列表 G 中组件的个数，这里对组件的定义为：链表中一段最长连续结点的值（该值必须在列表 G 中）构成的集合。
>

> 当时看题有点没看懂，花了时间。其实也就是从 `head` 节点顺序遍历，如果当前节点在列表 `G` 中没有被发现，就说明发生了中断，通过 `flag` 来判定是否需要对组件个数进行增加1的操作，也就是说，发生查找失败前是否存在有连续或者单个的节点，如果有就自增1，反之不增加。考虑通过`hash`来减少时间复杂度
>
> 再次熟悉了 `unordered_set<T> object, object.find(), object.insert()` 函数

# [109. 有序链表转换二叉搜索树](https://github.com/artintel/LeetCode/blob/master/109.%20%E6%9C%89%E5%BA%8F%E9%93%BE%E8%A1%A8%E8%BD%AC%E6%8D%A2%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91/source_code.cpp)

> 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
>
> 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
>
> 示例:
>
> 给定的有序链表： [-10, -3, 0, 5, 9],
>
> 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
>
>   ​         0
>      	  / \
>    ​	  -3   9
>    ​	  /    /
>     -10  5

> 了解参考了官方的解答。重点在于该有序链表本身就可以看做是二叉树的中序遍历。通过找到中位数的位置，来进行二叉搜索树的构建。
>
> ```c++
> TreeNode* root = new TreeNode();
> root->left = buildTreeNode(head, left, mid - 1);
> root->val = head->val;//左子树已经构建完毕，head已经到达了中位节点，实际就是根节点
> head = head->right;//构建右子树
> root->right = buildTreeNode(head, mid + 1, right);
> ```

# [剑指 Offer 18. 删除链表的节点](https://github.com/artintel/LeetCode/blob/master/%E5%89%91%E6%8C%87%20Offer%2018.%20%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E8%8A%82%E7%82%B9/source_code.cpp)

> 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
>
> 返回删除后的链表的头节点
>
> ```输入: head = [4,5,1,9], val = 5
> 输出: [4,1,9]
> 解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
> ```

# [剑指 Offer 22. 链表中倒数第k个节点](https://github.com/artintel/LeetCode/blob/master/%E5%89%91%E6%8C%87%20Offer%2022.%20%E9%93%BE%E8%A1%A8%E4%B8%AD%E5%80%92%E6%95%B0%E7%AC%ACk%E4%B8%AA%E8%8A%82%E7%82%B9/source_code.cpp)

> 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。
>
> ```输入: head = [4,5,1,9], val = 5
> 给定一个链表: 1->2->3->4->5, 和 k = 2.
> 
> 返回链表 4->5.
> ```

# [剑指 Offer 24. 反转链表](https://github.com/artintel/LeetCode/blob/master/%E5%89%91%E6%8C%87%20Offer%2024.%20%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8/source_code.cpp)

> 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点
>
> ```输入: head = [4,5,1,9], val = 5
> 输入: 1->2->3->4->5->NULL
> 输出: 5->4->3->2->1->NULL
> ```

