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

## [109. 有序链表转换二叉搜索树](https://github.com/artintel/LeetCode/blob/master/109.%20%E6%9C%89%E5%BA%8F%E9%93%BE%E8%A1%A8%E8%BD%AC%E6%8D%A2%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91/source_code.cpp)

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

## [剑指 Offer 18. 删除链表的节点](https://github.com/artintel/LeetCode/blob/master/%E5%89%91%E6%8C%87%20Offer%2018.%20%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E8%8A%82%E7%82%B9/source_code.cpp)

> 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
>
> 返回删除后的链表的头节点
>
> ```输入: head = [4,5,1,9], val = 5
> 输出: [4,1,9]
> 解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
> ```

## [剑指 Offer 22. 链表中倒数第k个节点](https://github.com/artintel/LeetCode/blob/master/%E5%89%91%E6%8C%87%20Offer%2022.%20%E9%93%BE%E8%A1%A8%E4%B8%AD%E5%80%92%E6%95%B0%E7%AC%ACk%E4%B8%AA%E8%8A%82%E7%82%B9/source_code.cpp)

> 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。
>
> ```输入: head = [4,5,1,9], val = 5
> 给定一个链表: 1->2->3->4->5, 和 k = 2.
> 
> 返回链表 4->5.
> ```

## [剑指 Offer 24. 反转链表](https://github.com/artintel/LeetCode/blob/master/%E5%89%91%E6%8C%87%20Offer%2024.%20%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8/source_code.cpp)

> 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点
>
> ```输入: head = [4,5,1,9], val = 5
> 输入: 1->2->3->4->5->NULL
> 输出: 5->4->3->2->1->NULL
> ```

## [面试题 02.02. 返回倒数第k个节点](https://github.com/artintel/LeetCode/blob/master/%E9%9D%A2%E8%AF%95%E9%A2%98%2002.02.%20%E8%BF%94%E5%9B%9E%E5%80%92%E6%95%B0%E7%AC%ACk%E4%B8%AA%E8%8A%82%E7%82%B9/source_code.txt)

> 实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。

> ```
> 输入： 1->2->3->4->5 和 k = 2
> 输出： 4
> ```

## [面试题 02.04. 链表求和](https://github.com/artintel/LeetCode/blob/master/%E9%9D%A2%E8%AF%95%E9%A2%98%2002.05.%20%E9%93%BE%E8%A1%A8%E6%B1%82%E5%92%8C/source_code.cpp)

> 给定两个用链表表示的整数，每个节点包含一个数位。
>
> 这些数位是反向存放的，也就是个位排在链表首部。
>
> 编写函数对这两个整数求和，并用链表形式返回结果。

> ```
> 输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
> 输出：2 -> 1 -> 9，即912
> ```
>
> 思路: 我定义了一个 `J` 也就是记录相加的进位,初始为 0
>
> 然后分为三个情况
>
> 1. `l1 != nullptr && l2 != nullptr` 那么就只需要同时相加，并且将进位也加上。同时更新新的进位 `J`
>
>    ```C++
>    sum = new ListNode(l1->val + l2->val + J) % 10;
>    J = (l1->val + l2->val + J) / 10;
>    ```
>    
> 2. `l1 != nullptr && l2 == nullptr`
>
> 3. `l1 == nullptr && l2 == nullptr`
>
> 4. 最后还要考虑两个链表都结束过后，进位 `J != 0`
>
>    ```C++
>    sum = new ListNode(J);
>    ```
>
> 最后，将所有节点连起来即可。

> **进阶：**思考一下，假设这些数位是正向存放的，又该如何解决呢?

>  ```
>  输入：(6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295
>  输出：9 -> 1 -> 2，即912
>  ```

> 用栈

## [面试题 02.03. 删除中间节点](https://github.com/artintel/LeetCode/blob/master/%E9%9D%A2%E8%AF%95%E9%A2%98%2002.03.%20%E5%88%A0%E9%99%A4%E4%B8%AD%E9%97%B4%E8%8A%82%E7%82%B9/source_code.cpp)

> 实现一种算法，删除单向链表中间的某个节点（即不是第一个或最后一个节点），假定你只能访问该节点。

> ```
> 输入：单向链表a->b->c->d->e->f中的节点c
> 结果：不返回任何数据，但该链表变为a->b->d->e->f
> ```

## [面试题 02.07. 链表相交](https://github.com/artintel/LeetCode/blob/master/%E9%9D%A2%E8%AF%95%E9%A2%98%2002.07%20%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4/source_code.cpp)

> 给定两个（单向）链表，判定它们是否相交并返回交点。请注意相交的定义基于节点的引用，而不是基于节点的值。换句话说，如果一个链表的第k个节点与另一个链表的第j个节点是同一节点（引用完全相同），则这两个链表相交。
>

> ```
> 输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
> 输出：Reference of the node with value = 8
> 输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
> ```

> 简单题，考虑双指针(还有其他的算法，没有去做)。
>
> 两个指针 `followA = headA; followB = headB` ,直接相遇就输出，否则 判断是否走到头
>
> ```C++
> followA ? followA = followA->next : followA = headB;
> followB ? followB = followB->next : followB = headA;
> ```

## [面试题 02.01. 移除重复节点](https://github.com/artintel/LeetCode/blob/master/%E9%9D%A2%E8%AF%95%E9%A2%98%2002.01.%20%E7%A7%BB%E9%99%A4%E9%87%8D%E5%A4%8D%E8%8A%82%E7%82%B9/source_code.cpp)

> 编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

> ```
> 输入：[1, 2, 3, 3, 2, 1]
> 输出：[1, 2, 3]
> ```

> 考虑用哈希map保存值`<int, int> (val, 0)`，每次检查代删除点是否已经存在:
>
> ```
> if (map[val] == 0) {
> 	map[val] = 1;
> 	pre->next = cur;
> 	pre = pre->next;
> 	cur = cur->next;
> }
> esle{
> 	cur = cur->next;
> }
> ```
>
> 由此即可删除重复点。

## [6. Z 字形变换](https://github.com/artintel/LeetCode/blob/master/6.%20Z%20%E5%AD%97%E5%BD%A2%E5%8F%98%E6%8D%A2/source_code.cpp)

> 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
>
> 比如输入字符串为 `"LEETCODEISHIRING"` 行数为 3 时，排列如下：

> ```
> L   C   I   R
> E T O E S I I G
> E   D   H   N
> ```

> 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如：`"LCIRETOESIIGEDHN"`。
>
> 请你实现这个将字符串进行指定行数变换的函数：
>
> ```C++
> string convert(string s, int numRows);
> ```
>
> **示例 1:** 
>
> ```C++
> 输入: s = "LEETCODEISHIRING", numRows = 3
> 输出: "LCIRETOESIIGEDHN"
> ```
>
> **示例 2:** 
>
> ```C++
> 输入: s = "LEETCODEISHIRING", numRows = 4
> 输出: "LDREOEIIECIHNTSG"
> 解释:
> 
> L     D     R
> E   O E   I I
> E C   I H   N
> T     S     G
> ```
>
> 题解来自官方。第一个解的方法在于用`bool goingDown = true or false 来进行Z字形赋值` 很厉害
>
> 第二种方法就是
>
> **思路**
>
> 按照与逐行读取 Z 字形图案相同的顺序访问字符串。
>
> **算法**
>
> 首先访问行 0 中的所有字符，接着访问行 1，然后行 2，依此类推...
>
> 对于所有整数 `k`，
>
> - 行 0 中的字符位于索引 `k * (2 * numRows - 2) `处;
> - 行 `numRows-1 `中的字符位于索引 `k* (2 * numRows - 2) + numRows - 1 `处;
> - 内部的 行 `i` 中的字符位于索引 `k * (2 * numRows-2) + i `以及`(k+1)(2 * numRows - 2) - i `处;
>

## [面试题 02.06. 回文链表](https://github.com/artintel/LeetCode/blob/master/%E9%9D%A2%E8%AF%95%E9%A2%98%2002.06.%20%E5%9B%9E%E6%96%87%E9%93%BE%E8%A1%A8/source_code.cpp)

> 编写一个函数，检查输入的链表是否是回文的。

> ```
> 输入： 1->2
> 输出： false 
> ```

> 用快慢指针找到中间节点的前一个节点，从中间断开，前面一般的链表入栈，进行比较
>
> ```C++
> while(!ans.empty()){
> 	if (ans.top() != fast->val) break;
>     ans.pop();
>     fast = fast->next;
> }
> return ans.empty() ? true : false;
> ```

## [面试题 02.08. 环路检测](https://github.com/artintel/LeetCode/blob/master/%E9%9D%A2%E8%AF%95%E9%A2%98%2002.08.%20%E7%8E%AF%E8%B7%AF%E6%A3%80%E6%B5%8B/source_code.cpp)

> 给定一个链表，如果它是有环链表，实现一个算法返回环路的开头节点。
>
> 如果链表中有某个节点，可以通过连续跟踪 `next` 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 `pos` 来表示链表尾连接到链表中的位置（索引从 `0` 开始）。 如果 `pos` 是 `-1`，则在该链表中没有环。注意：`pos` 不作为参数进行传递，仅仅是为了标识链表的实际情况
>

> ```
> 输入：head = [3,2,0,-4], pos = 1
> 输出：tail connects to node index 1
> 解释：链表中有一个环，其尾部连接到第二个节点。
> ```

> (自己的方法简单暴力：`unordered_set<ListNode*>`, 来逐个保存节点，每次保存之前通过`set.count(head)`,来判断是否已经有相同的节点在里面了，如果有就说明找到了环路，并且找到了环路的入口，如果遇到`head == nullptr`，则说明没有环路，返回`nullptr`)

> 大佬的方法：数学证明：
>
> 如果链表中有环，那么快慢指针就一定可以相遇（且一定再环上，如图上的c点），此时快指针移动过的距离是慢指针的2倍，根据图中的参数，我们可以写出以下等式：
>
> ```mathematica
> (m+y)*2=m+xn+y
> ```
>
> 这里的 `xn` 是当相遇时快指针已经在环上循环了 `x` 次，` x>=1` 且为整数
>
> ```mathematica
> m+y=xn => m=n-y+(x-1)*n
> ```
>
> 下面解释为什么写成这种形式
>
> 接下来将快指针置于表头(此时快指针在 `a` 处，慢指针在 `c` 处)，与慢指针以相同速度在链表上移动，当快指针移动到 `b` 处时，移动了 `m` 的距离，根据上面的等式可知，慢指针移动了
>
> ```mathematica
> n-y+(x-1)*n
> ```
>
> 的距离。
>
> 我们来分析一下此时的慢指针在什么位置：
> 先移动 `(x-1)*n` 的距离，相当于在环上循环了 `(x-1)` 次，慢指针又回到了 `c` 点，然后再移动 `n-y` 的距离，如图所示，`n-y` 正好是 `c` 点到 `b` 点的距离，说明此时慢指针也移动到了 `b` 点，即快慢指针在环路的开头节点相遇了。
>
> 来源：力扣（LeetCode）https://leetcode-cn.com/u/chen-hui-d/ 晨辉
> 链接：https://leetcode-cn.com/problems/linked-list-cycle-lcci/solution/kuai-man-zhi-zhen-zheng-ming-bi-jiao-yan-jin-by-ch/

## [面试题 02.04. 分隔链表](https://github.com/artintel/LeetCode/blob/master/%E9%9D%A2%E8%AF%95%E9%A2%98%2002.04.%20%E5%88%86%E9%9A%94%E9%93%BE%E8%A1%A8/source_code.cpp)

> 编写程序以 x 为基准分割链表，使得所有小于 x 的节点排在大于或等于 x 的节点之前。如果链表中包含 x，x 只需出现在小于 x 的元素之后(如下所示)。分割元素 x 只需处于“右半部分”即可，其不需要被置于左右两部分之间。
>

> ```
> 输入: head = 3->5->8->5->10->2->1, x = 5
> 输出: 3->1->2->10->5->5->8
> ```

> 实际只需要考虑 `node->val < x` 的节点即可，将所有满足条件的节点用另一条链表连接，最后将两个列表连接在一起，即可

## [430. 扁平化多级双向链表](https://github.com/artintel/LeetCode/blob/master/430.%20%E6%89%81%E5%B9%B3%E5%8C%96%E5%A4%9A%E7%BA%A7%E5%8F%8C%E5%90%91%E9%93%BE%E8%A1%A8/source_code.cpp)

> 多级双向链表中，除了指向下一个节点和前一个节点指针之外，它还有一个子链表指针，可能指向单独的双向链表。这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。
>
> 给你位于列表第一级的头节点，请你扁平化列表，使所有结点出现在单级双链表中。
>

> ```
> 输入：head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
> 输出：[1,2,3,7,8,11,12,9,10,4,5,6]
> ```

> 可以竖向的看，就能看出是很简单的二叉树的数据结构，再经过前序遍历，通过一个STL的队列数据结构。将节点一次放入队列中，最后再通过
>
> ```C++
> while(!ans.empty()){
>     temp = ans.front();
>     ans.pop();
>     if(ans.empty()) break;
>     else{
>         temp->next = ans.front();
>         ans.front()->prev = temp;
>         temp->child = nullptr;
>     }
> }
> temp->next = nullptr;
> temp->child = nullptr;
> ```
>
> 就可以完成扁平化双向链表。

## [23. 合并K个升序链表](https://github.com/artintel/LeetCode/blob/master/23.%20%E5%90%88%E5%B9%B6k%E4%B8%AA%E5%8D%87%E5%BA%8F%E9%93%BE%E8%A1%A8/source_code.cpp)

> 给你一个链表数组，每个链表都已经按升序排列。
>
> 请你将所有链表合并到一个升序链表中，返回合并后的链表。

> ```
> 输入：lists = [[1,4,5],[1,3,4],[2,6]]
> 输出：[1,1,2,3,4,4,5,6]
> 解释：链表数组如下：
> [
>   1->4->5,
>   1->3->4,
>   2->6
> ]
> 将它们合并到一个有序链表中得到。
> 1->1->2->3->4->4->5->6
> 
> 输入：lists = []
> 输出：[]
> 
> 输入：lists = [[]]
> 输出：[]
> ```

> 自己的思路:顺序地两两合并。但是效率很差
>
> 官方思路:
>
> 1. 分治法
> 2. 队列合并

## [25. K 个一组反转链表](https://github.com/artintel/LeetCode/blob/master/25.%20K%E4%B8%AA%E4%B8%80%E7%BB%84%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8/source_code.cpp)

> 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
>
> k 是一个正整数，它的值小于或等于链表的长度。
>
> 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
>
> ```
> 给你这个链表：1->2->3->4->5
> 
> 当 k = 2 时，应当返回: 2->1->4->3->5
> 
>   当 k = 3 时，应当返回: 3->2->1->4->5
>   ```

> 解题思路：
>
> 考虑将每 K 个一组的子链表单独拿出来进行反转。那么就需要考虑反转后和前序后缀的连接。因此定义了如下的中转变量
>
> ```c++
> //new 一个新的头节点，next指向head
> ListNode* Head = new ListNode(-1);
> //定义一个计数器m,查看是否有m个结点进入
> int m = 1;
> //定义一个指针指向每段要进行反转的子链表的直接前序。
> ListNode* pre = Head;
> //定义一个指针指向子链表的头节点
> ListNode* behind = head;
> //定义一个当前的位置的指针
> ListNode* cur = head;
> //定义一个指向子链表的直接后缀
> ListNode* tail;
> ```

## [26. 删除排序数组中的重复项](https://github.com/artintel/LeetCode/blob/master/26.%20%E5%88%A0%E9%99%A4%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E9%87%8D%E5%A4%8D%E9%A1%B9/source_code.cpp)

> 给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
>
> 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
>

> ```
> 给定数组 nums = [1,1,2], 
> 
> 函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 
> 
> 你不需要考虑数组中超出新长度后面的元素。
> ```

> 用一个 left 一直指在重复数值的第一个(也可以理解成新的子数组的最后一个值)
> 用for循环遍历过程的 i 作为第二个“指针”，当遇到和left指的数值不一样的时候，
> `nums[left + 1] = nums[i];`
> 遍历结束 `nums.resize(left + 1);`
> `return left + 1`;

## [27. 移除元素](https://github.com/artintel/LeetCode/blob/master/27.%20%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0/source_code.cpp)

> 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
>
> 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
>
> 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
>

> ```
> 给定 nums = [3,2,2,3], val = 3,
> 
> 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
> 
> 你不需要考虑数组中超出新长度后面的元素。
> ```

> 双指针：用 `pre` 指在新数组的最后一个，有 `behind` 来遍历数组，当遇到 `nums[behind] != val;` 时，就将 `behind` 所指元素放入到 `pre`位置

## [35. 搜索插入位置](https://github.com/artintel/LeetCode/blob/master/35.%20%E6%90%9C%E7%B4%A2%E6%8F%92%E5%85%A5%E4%BD%8D%E7%BD%AE/source_code.cpp)

> 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
>
> 你可以假设数组中无重复元素。

> ```
> 输入: [1,3,5,6], 5
> 输出: 2
> 输入: [1,3,5,6], 2
> 输出: 1
> 输入: [1,3,5,6], 7
> 输出: 4
> 输入: [1,3,5,6], 0
> 输出: 0
> ```

> 二分查找

## [53. 最大子序和](https://github.com/artintel/LeetCode/blob/master/53.%20%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%92%8C/source_code.cpp)

> 给定一个整数数组 `nums` ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

> ```
> 输入: [-2,1,-3,4,-1,2,1,-5,4]
> 输出: 6
> 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
> ```

> - 动态规划， 分别定义了 temp 记录以当前位置为结点的最大序列和是多少， max 记录真正最大的和；
>
>    ```C++
>    for(const auto& x : nums){
>        temp = max(temp + x, x);
>        MAX = max(temp, MAX);
>    }
>    ```
>
> - 分治法：
>
>   思路和算法
>
>   我们定义一个操作 `get(a, l, r)` 表示查询 `a` 序列 `[l, r]` 区间内的最大子段和，那么最终我们要求的答案就是 `get(nums, 0, nums.size() - 1)`。如何分治实现这个操作呢？对于一个区间 `[l, r]`，我们取 $m = \lfloor \frac{l + r}{2} \rfloor m =⌊ 2 \cdot l+r ⌋$，对区间 `[l, m]` 和 `[m + 1, r]` 分治求解。当递归逐层深入直到区间长度缩小为 11 的时候，递归「开始回升」。这个时候我们考虑如何通过 `[l, m]` 区间的信息和 `[m + 1, r]` 区间的信息合并成区间 `[l, r]` 的信息。最关键的两个问题是：
>   
>   - 我们要维护区间的哪些信息呢？
>   
>   - 我们如何合并这些信息呢？
>   
>   对于一个区间 `[l, r]`,  我们可以维护四个量：
>   
>   - lSum 表示 `[l, r]` 内以 ll 为左端点的最大子段和
>   
>   - rSum 表示 `[l, r]` 内以 rr 为右端点的最大子段和
>   
>   - mSum 表示 `[l, r]` 内的最大子段和
>   
>   - iSum 表示 `[l, r]` 的区间和
>   
>   以下简称 `[l, m]` 为 `[l, r]` 的「左子区间」， `[m + 1, r]` 为 `[l, r]` 的「右子区间」。我们考虑如何维护这些量呢（如何通过左右子区间的信息合并得到 `[l, r]` 的信息）？对于长度为 1 的区间 `[i, i]` ，四个量的值都和 $ a_i $ 相等。对于长度大于 1 的区间：
>   
>   - 首先最好维护的是 `iSum`，区间 `[l, r]` 的 `iSum` 就等于「左子区间」的 `iSum` 加上「右子区间」的 `iSum`。
>   - 对于 `[l, r]` 的 `lSum`，存在两种可能，它要么等于「左子区间」的 `lSum`，要么等于「左子区间」的 `iSum` 加上「右子区间」的 `lSum`，二者取大。
>   - 对于 `[l, r]` 的 `rSum`，同理，它要么等于「右子区间」的 `rSum`，要么等于「右子区间」的 `iSum` 加上「左子区间」的 `rSum`，二者取大。
>   - 当计算好上面的三个量之后，就很好计算 `[l, r]` 的 `mSum` 了。我们可以考虑 `[l, r]` 的 `mSum` 对应的区间是否跨越 `m` ——它可能不跨越 `m`，也就是说 `[l, r]` 的 `mSum` 可能是「左子区间」的 `mSum` 和 「右子区间」的 `mSum` 中的一个；它也可能跨越 `m`，可能是「左子区间」的 `rSum` 和 「右子区间」的 `lSum` 求和。三者取大。
>   
>   作者：LeetCode-Solution
>   链接：https://leetcode-cn.com/problems/maximum-subarray/solution/zui-da-zi-xu-he-by-leetcode-solution/
>   来源：力扣（LeetCode）
>   著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
> 

## [66. 加一](https://github.com/artintel/LeetCode/blob/master/66.%20%E5%8A%A0%E4%B8%80/source_code.cpp)

> 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
>
> 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
>
> 你可以假设除了整数 0 之外，这个整数不会以零开头。
>

> ```
> 输入：digits = [1,2,3]
> 输出：[1,2,4]
> 解释：输入数组表示数字 123。
> 
> 输入：digits = [0]
> 输出：[1]
> ```

## [88. 合并两个有序数组](https://github.com/artintel/LeetCode/blob/master/88.%20%E5%90%88%E5%B9%B6%E4%B8%A4%E4%B8%AA%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84/source_code.cpp)

> 给你两个有序整数数组 *nums1* 和 *nums2*，请你将 *nums2* 合并到 *nums1* 中*，*使 *nums1* 成为一个有序数组。

> - 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
> - 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

> ```
> 输入：
> nums1 = [1,2,3,0,0,0], m = 3
> nums2 = [2,5,6],       n = 3
> 
> 输出：[1,2,2,3,5,6]
> ```

> 先用额外的 `vector<int> num` 拷贝 `nums1`, 双指针分别遍历 `nums1, nums2`, 将值小的放入 `nums1`， 因为 `nums1`已被复制，所以无须考虑`nums1` 内的值是否被占用所以是安全的

## [118. 杨辉三角](https://github.com/artintel/LeetCode/blob/master/118.%20%E6%9D%A8%E8%BE%89%E4%B8%89%E8%A7%92/source_code.cpp)

> 给定一个非负整数 *numRows，*生成杨辉三角的前 *numRows* 行。

> ```
> 输入: 5
> 输出:
> [
>      [1],
>     [1,1],
>    [1,2,1],
>   [1,3,3,1],
>  [1,4,6,4,1]
> ]
> ```

> 1. vector<vector<int> > ans;
>
> 2. vector<int> temp;
>
> 3. ```
>    while(cur <= i){
>        if(cur == 0 || cur == i){
>        temp.emplace_back(1);
>        cur++;
>    }
>    else{
>        temp.emplace_back(ans[i - 1][cur - 1] + ans[i - 1][cur]);
>        cur++;
>        }
>    }
>    ans.emplace_back(temp);
>    ```
>

## [119. 杨辉三角II](https://github.com/artintel/LeetCode/blob/master/119.%20%E6%9D%A8%E8%BE%89%E4%B8%89%E8%A7%92II/source_code.cpp)

> 给定一个非负索引 *k*，其中 *k* ≤ 33，返回杨辉三角的第 *k* 行。

> ```
> 输入: 3
> 输出: [1,3,3,1]
> ```

> 动态规划
>
> ```C++
> vector<int> dp(rowIndex + 1, 1);
>     for (int i = 1; i <= rowIndex; i++) {
>         for (int j = i - 1; j >= 1; j--) {
>             dp[j] = dp[j - 1] + dp[j];
>         }
>     }
> ```
>
> 这个优化可以将空间复杂度控制为 O(k)；

## [121. 买卖股票的最佳时机](https://github.com/artintel/LeetCode/blob/master/121.%20%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA/source_code.cpp)

> 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
>
> 如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
>
> 注意：你不能在买入股票前卖出股票。
>

> ```
> 输入: [7,1,5,3,6,4]
> 输出: 5
> 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
>      注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
> ```

> ```C++
> 输入: [7,6,4,3,1]
> 输出: 0
> 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。vector<int> dp(rowIndex + 1, 1);
>     for (int i = 1; i <= rowIndex; i++) {
>         for (int j = i - 1; j >= 1; j--) {
>             dp[j] = dp[j - 1] + dp[j];
>         }
>     }
> ```

## [122. 买卖股票的最佳时机 II](https://github.com/artintel/LeetCode/blob/master/122.%20%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA%20II/source_code.cpp)

> 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
>
> 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
>
> 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
>

> ```
> 输入: [7,1,5,3,6,4]
> 输出: 7
> 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
>      随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
> ```

> ```
> 输入: [1,2,3,4,5]
> 输出: 4
> 解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
>      注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
>      因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
> ```

> 思路同121

## [167. 两数之和 II - 输入有序数组](https://github.com/artintel/LeetCode/blob/master/167.%20%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C%20II-%20%E8%BE%93%E5%85%A5%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84/source_code.cpp)

> 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
>
> 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
>

> ```
> 输入: numbers = [2, 7, 11, 15], target = 9
> 输出: [1,2]
> 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 
> ```

> 思路：
>
> 先用二分查找发找到不大于 target 的值的 Index, 用双指针分别指向数组起点和 index。如此，分为了三种情况
>
> 1. ```C++
>    if(numbers[i] + numbers[j] == target){
>        ans.emplace_back(min(i, j) + 1);
>        ans.emplace_back(max(i, j) + 1);
>        break;
>    }
>    ```
>
> 2. ```C++
>    else if (numbers[i] + numbers[j] > target){
>        j--;
>    }
>    ```
>
> 3. ```C++
>    else i++;
>    ```

## [169. 多数元素](https://github.com/artintel/LeetCode/blob/master/169.%20%E5%A4%9A%E6%95%B0%E5%85%83%E7%B4%A0/source_code.cpp)

> 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
>
> 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
>

> ```
> 输入: [3,2,3]
> 输出: 3
> ```

> 思路：
>
> 第一种：
>
> 我们使用哈希映射（HashMap）来存储每个元素以及出现的次数。对于哈希映射中的每个键值对，键表示一个元素，值表示该元素出现的次数。
>
> 我们用一个循环遍历数组 nums 并将数组中的每个元素加入哈希映射中。在这之后，我们遍历哈希映射中的所有键值对，返回值最大的键。我们同样也可以在遍历数组 nums 时候使用打擂台的方法，维护最大的值，这样省去了最后对哈希映射的遍历。
>
> 第二种：
>
> 排序，因为众数必定大于  `⌊ n/2 ⌋`， 所以在排序后，`nums[nums.size() >> 1] 的数必定是众数`

## [217. 存在重复元素](https://github.com/artintel/LeetCode/blob/master/217.%20%E5%AD%98%E5%9C%A8%E9%87%8D%E5%A4%8D%E5%85%83%E7%B4%A0/source_code.cpp)

> 给定一个整数数组，判断是否存在重复元素。
>
> 如果任意一值在数组中出现至少两次，函数返回 `true` 。如果数组中每个元素都不相同，则返回 `false` 。

> ```
> 输入: [1,2,3,1]
> 输出: true
> ```

## [219. 存在重复元素II](https://github.com/artintel/LeetCode/tree/master/219.%20%E5%AD%98%E5%9C%A8%E9%87%8D%E5%A4%8D%E5%85%83%E7%B4%A0%20II)

> 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。
>

> ```
> 输入: nums = [1,2,3,1], k = 3
> 输出: true
> 
> 输入: nums = [1,0,1,1], k = 1
> 输出: true
> ```
>
> 利用 hash (unordered_set)

## [228. 汇总区间](https://github.com/artintel/LeetCode/blob/master/228.%20%E6%B1%87%E6%80%BB%E5%8C%BA%E9%97%B4/source_code.cpp)

> 给定一个无重复元素的有序整数数组 nums 。
>
> 返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于 nums 的数字 x 。
>
> 列表中的每个区间范围 [a,b] 应该按如下格式输出：
>
> - "a->b" ，如果 a != b
> - "a" ，如果 a == b

> ```
> 输入：nums = [0,1,2,4,5,7]
> 输出：["0->2","4->5","7"]
> 解释：区间范围是：
> [0,2] --> "0->2"
> [4,5] --> "4->5"
> [7,7] --> "7"
> 
> 输入：nums = [0,2,3,4,6,8,9]
> 输出：["0","2->4","6","8->9"]
> 解释：区间范围是：
> [0,0] --> "0"
> [2,4] --> "2->4"
> [6,6] --> "6"
> [8,9] --> "8->9"
> 
> 输入：nums = []
> 输出：[]
> 
> 输入：nums = [0]
> 输出：["0"]
> ```
>
> 思路很简单，需要考虑的是是否越界，当 nums[i] 为大正整数， nums[i - 1] 为大的负整数时，如果使用 `nums[i] - nums[i - 1] == 1?` 作为条件边界的话，可能出现内存溢出的情况，所以使用 `nums[i - 1] + 1 == nums[i] ? ` 来作为条件边界

## [268. 丢失的数字](https://github.com/artintel/LeetCode/blob/master/268.%20%E4%B8%A2%E5%A4%B1%E7%9A%84%E6%95%B0%E5%AD%97/source_code.cpp)

> 给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。
>
> 进阶：
>
> 你能否实现线性时间复杂度、仅使用额外常数空间的算法解决此问题?
>

> ```
> 输入：nums = [3,0,1]
> 输出：2
> 解释：n = 3，因为有 3 个数字，所以所有的数字都在范围 [0,3] 内。2 是丢失的数字，因为它没有出现在 nums 中。
> 
> 输入：nums = [9,6,4,2,3,5,7,0,1]
> 输出：8
> 解释：n = 9，因为有 9 个数字，所以所有的数字都在范围 [0,9] 内。8 是丢失的数字，因为它没有出现在 nums 中。
> 
> 输入：nums = [0]
> 输出：1
> 解释：n = 1，因为有 1 个数字，所以所有的数字都在范围 [0,1] 内。1 是丢失的数字，因为它没有出现在 nums 中。
> ```
>
> 利用(a[0] + a[n]) * n / 2公式

## [283. 移动零](https://github.com/artintel/LeetCode/blob/master/283.%20%E7%A7%BB%E5%8A%A8%E9%9B%B6/source_code.cpp)

> 给定一个数组 `nums`，编写一个函数将所有 `0` 移动到数组的末尾，同时保持非零元素的相对顺序

> ```
> 输入: [0,1,0,3,12]
> 输出: [1,3,12,0,0]
> ```
>
> 堆排序

## [414. 第三大的数](https://github.com/artintel/LeetCode/blob/master/414.%20%E7%AC%AC%E4%B8%89%E5%A4%A7%E7%9A%84%E6%95%B0/source_code.cpp)

> 给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。

> ```
> 输入: [3, 2, 1]
> 
> 输出: 1
> 
> 解释: 第三大的数是 1.
> 
> 输入: [1, 2]
> 
> 输出: 2
> 
> 解释: 第三大的数不存在, 所以返回最大的数 2 .
> 
> 输入: [2, 2, 3, 1]
> 
> 输出: 1
> 
> 解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
> 存在两个值为2的数，它们都排第二。
> ```
>
> 1. 用了归并排序
> 2. 用了小顶堆

## [448. 找到所有数组中消失的数字](https://github.com/artintel/LeetCode/blob/master/448.%20%E6%89%BE%E5%88%B0%E6%89%80%E6%9C%89%E6%95%B0%E7%BB%84%E4%B8%AD%E6%B6%88%E5%A4%B1%E7%9A%84%E6%95%B0%E5%AD%97/source_code.cpp)

> 给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
>
> 找到所有在 [1, n] 范围之间没有出现在数组中的数字。
>
> 您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。
>

> ```
> 输入:
> [4,3,2,7,8,2,3,1]
> 
> 输出:
> [5,6]
> ```
>
> - 遍历输入数组的每个元素一次。
> - 我们将把 `|nums[i]|-1` 索引位置的元素标记为负数。即 `nums[|nums[i]| - 1] * -1` 。
> - 然后遍历数组，若当前数组元素 `nums[i]` 为负数，说明我们在数组中存在数字 `i+1`。
>
> 作者：LeetCode
> 链接：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/solution/zhao-dao-suo-you-shu-zu-zhong-xiao-shi-de-shu-zi-2/
> 来源：力扣（LeetCode）
> 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

## [485. 最大连续1的个数](https://github.com/artintel/LeetCode/blob/master/485.%20%E6%9C%80%E5%A4%A7%E8%BF%9E%E7%BB%AD1%E7%9A%84%E4%B8%AA%E6%95%B0/source_code.cpp)

> 给定一个二进制数组， 计算其中最大连续1的个数。

> ```
> 输入: [1,1,0,1,1,1]
> 输出: 3
> 解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
> ```
>
> 利用状态机来做。
>
> 根据当前数字的值，和当前状态进行判断。
>
> ```
> if elem == 1:
> 	如果当前状态是 true;
> 		temp_1 += 1;
> 	如果当前状态是 false;
> 		将当前状态改为 true;
> 		temp_1 += 1;
> if elem != 1:
> 	如果当前状态是 false;
> 		continue;
> 	如果当前状态时 true;
> 		max_1 = max(max_1, temp_1);
> 		将状态改为 false;
> ```

## [561. 数组拆分 I](https://github.com/artintel/LeetCode/blob/master/561.%20%E6%95%B0%E7%BB%84%E6%8B%86%E5%88%86%20I/source_code.cpp)

> 给定长度为 2n 的整数数组 nums ，你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从 1 到 n 的 min(ai, bi) 总和最大。
>
> 返回该 最大总和 。
>

> ```
> 输入：nums = [1,4,3,2]
> 输出：4
> 解释：所有可能的分法（忽略元素顺序）为：
> 1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
> 2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
> 3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
> 所以最大总和为 4
> ```
>
> 排序：并且选取排序后每组的第一个数
>

## [566. 重塑矩阵](https://github.com/artintel/LeetCode/blob/master/566.%20%E9%87%8D%E5%A1%91%E7%9F%A9%E9%98%B5/source_code.cpp)

> 在MATLAB中，有一个非常有用的函数 reshape，它可以将一个矩阵重塑为另一个大小不同的新矩阵，但保留其原始数据。
>
> 给出一个由二维数组表示的矩阵，以及两个正整数r和c，分别表示想要的重构的矩阵的行数和列数。
>
> 重构后的矩阵需要将原始矩阵的所有元素以相同的行遍历顺序填充。
>
> 如果具有给定参数的reshape操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。

> ```
> 输入: 
> nums = 
> [[1,2],
>  [3,4]]
> r = 1, c = 4
> 输出: 
> [[1,2,3,4]]
> 解释:
> 行遍历nums的结果是 [1,2,3,4]。新的矩阵是 1 * 4 矩阵, 用之前的元素值一行一行填充新矩阵。
> ```
>

> 还是相对比较暴力的：将 `nums` 原数组数据遍历出来放在新的 `vector` 容器中，再通过一个双循环进行遍历进行`reshape` 操作

## [506. 斐波那契数列](https://github.com/artintel/LeetCode/blob/master/506.%20%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%88%97/source_code.cpp)

> **斐波那契数**，通常用 `F(n)` 表示，形成的序列称为**斐波那契数列**。该数列由 `0` 和 `1` 开始，后面的每一项数字都是前面两项数字的和。也就是：

> ```
> F(0) = 0,   F(1) = 1
> F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
> ```

> 除开最常见的递归，参考邓俊辉老师的动态规划自底向上的方法：
>
> 因为递归会做很多重复的方式，通过两个变量动态地更新来找到所需要的 `fib(n)` 的值
>
> ```C++
> int f = 0, g = 1;
> while(--n){
> 	g = f + g;
> 	f = g - f;
> }
> return g;
> ```

## [面试题 01.01. 判定字符是否唯一](https://github.com/artintel/LeetCode/blob/master/%E9%9D%A2%E8%AF%95%E9%A2%98%2001.01.%20%E5%88%A4%E5%AE%9A%E5%AD%97%E7%AC%A6%E6%98%AF%E5%90%A6%E5%94%AF%E4%B8%80/source_code.cpp)

> 实现一个算法，确定一个字符串 `s` 的所有字符是否全都不同

> ```
> 输入: s = "leetcode"
> 输出: false 
> 
> 输入: s = "abc"
> 输出: true
> ```

> **限制：**
>
> - `0 <= len(s) <= 100`
> - 如果你不使用额外的数据结构，会很加分。

> 通过限制我们可以考虑使用位判定。字符总数为26个。那么定义一个 int 型足够。再通过左移和异或运算即可求得是否有重复

## [面试题 08.03. 魔术索引](https://github.com/artintel/LeetCode/blob/master/%E9%9D%A2%E8%AF%95%E9%A2%98%2008.03.%20%E9%AD%94%E6%9C%AF%E7%B4%A2%E5%BC%95/source_code.cpp)

> 魔术索引。 在数组A[0...n-1]中，有所谓的魔术索引，满足条件A[i] = i。给定一个有序整数数组，编写一种方法找出魔术索引，若有的话，在数组A中找出一个魔术索引，如果没有，则返回-1。若有多个魔术索引，返回索引值最小的一个。
>

> ```
>  输入：nums = [0, 2, 3, 4, 5]
>  输出：0
>  说明: 0下标的元素为0
> ```

> 用了暴力求解，线性扫描。但是在扫描过程中可以注意到:
>
> 数组是有序的， 那么当 `nums[i] < i` 的时候，在进行下一轮之前， 可以让 `i` 跳至 `nums[i]`, 即 `i = nums[i]`

## [面试题 01.02. 判定是否互为字符重排](https://github.com/artintel/LeetCode/blob/master/%E9%9D%A2%E8%AF%95%E9%A2%98%2001.02.%20%E5%88%A4%E5%AE%9A%E6%98%AF%E5%90%A6%E4%BA%92%E4%B8%BA%E5%AD%97%E7%AC%A6%E9%87%8D%E6%8E%92/source_code.cpp)

> 给定两个字符串 `s1` 和 `s2`，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

> ```
> 输入: s1 = "abc", s2 = "bca"
> 输出: true 
> 
> 输入: s1 = "abc", s2 = "bad"
> 输出: false
> ```

> 定义两个set,分别储存两个字符串中个字符出现的个数，最后再检查是否出现频率相等

## [605. 种花问题](https://github.com/artintel/LeetCode/blob/master/605.%20%E7%A7%8D%E8%8A%B1%E9%97%AE%E9%A2%98/source_code.cpp)

> 假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
>
> 给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。
>

> ```
> 输入: flowerbed = [1,0,0,0,1], n = 1
> 输出: True
> 
> 输入: flowerbed = [1,0,0,0,1], n = 2
> 输出: False
> ```

> 考虑贪心算法+状态机，status 初始化为 true
>
> ```c++
> 判断当前位置是否为零：
>     if true & 状态机 false:
> 		状态机改为 true,表示下一个有可能能够种花
>     if true & 状态机 true & 下一个位置也为 0 :
> 		可以种花，status转为false;、
>         if i + 1 越界：
>             count++;
> 			break;
> 如果当前不为0，status == true:
> 	status = false;
> return count >= n ? true : false;
> ```
>

## [70. 爬楼梯](https://github.com/artintel/LeetCode/blob/master/70.%20%E7%88%AC%E6%A5%BC%E6%A2%AF/source_code.cpp)

> 假设你正在爬楼梯。需要 *n* 阶你才能到达楼顶。
>
> 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
>
> **注意：**给定 *n* 是一个正整数。

> ```
> 输入： 2
> 输出： 2
> 解释： 有两种方法可以爬到楼顶。
> 1.  1 阶 + 1 阶
> 2.  2 阶
> 
> 
> 输入： 3
> 输出： 3
> 解释： 有三种方法可以爬到楼顶。
> 1.  1 阶 + 1 阶 + 1 阶
> 2.  1 阶 + 2 阶
> 3.  2 阶 + 1 阶
> ```

> 动态规划，自底向上 爬楼梯和斐波那契数列是一样的题

## [198. 打家劫舍](https://github.com/artintel/LeetCode/blob/master/198.%20%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8D/source_code.cpp)

> 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
>
> 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
>

> ```
> 输入：[1,2,3,1]
> 输出：4
> 解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
>      偷窃到的最高金额 = 1 + 3 = 4 。
> 
> 输入：[2,7,9,3,1]
> 输出：12
> 解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
>      偷窃到的最高金额 = 2 + 9 + 1 = 12 。
> ```

> 动态规划遍历
>
> 对于当前的房屋，考虑 `dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])`
>
> 边界条件：
>
>  `dp[0] = nums[0], `
>
>  `dp[1] = max(nums[0], nums[1]);`

> 首先考虑最简单的情况。如果只有一间房屋，则偷窃该房屋，可以偷窃到最高总金额。如果只有两间房屋，则由于两间房屋相邻，不能同时偷窃，只能偷窃其中的一间房屋，因此选择其中金额较高的房屋进行偷窃，可以偷窃到最高总金额。
>
> 如果房屋数量大于两间，应该如何计算能够偷窃到的最高总金额呢？对于第 k(k>2) 间房屋，有两个选项：
>
> 偷窃第 k 间房屋，那么就不能偷窃第 k-1 间房屋，偷窃总金额为前 k−2 间房屋的最高总金额与第 k 间房屋的金额之和。
>
> 不偷窃第 k 间房屋，偷窃总金额为前 k-1 间房屋的最高总金额。
>
> 在两个选项中选择偷窃总金额较大的选项，该选项对应的偷窃总金额即为前 kk 间房屋能偷窃到的最高总金额。
>
> 用 dp[i] 表示前 i 间房屋能偷窃到的最高总金额，那么就有如下的状态转移方程：
>
> `dp[i] = max(dp[i-2]+nums[i], dp[i-1])`
>
> 
>
>
> 最终的答案即为 dp[n-1]，其中 n 是数组的长度。
>
> 作者：LeetCode-Solution
> 链接：https://leetcode-cn.com/problems/house-robber/solution/da-jia-jie-she-by-leetcode-solution/
> 来源：力扣（LeetCode）
> 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

## [303. 区域和检索 - 数组不可变](https://github.com/artintel/LeetCode/blob/master/303.%20%E5%8C%BA%E5%9F%9F%E5%92%8C%E6%A3%80%E6%B5%8B%20-%20%E6%95%B0%E7%BB%84%E4%B8%8D%E5%8F%AF%E5%8F%98/source_code.cpp)

> 给定一个整数数组  nums，求出数组从索引 i 到 j（i ≤ j）范围内元素的总和，包含 i、j 两点。
>
> 实现 NumArray 类：
>
> - `NumArray(int[] nums)` 使用数组 `nums` 初始化对象
> - `int sumRange(int i, int j)` 返回数组 `nums` 从索引 `i` 到 `j（i ≤ j）`范围内元素的总和，包含 `i、j `两点（也就是 `sum(nums[i], nums[i + 1], ... , nums[j])`）

> ```
> 输入： 2
> 输出： 2
> 解释： 有两种方法可以爬到楼顶。
> 1.  1 阶 + 1 阶
> 2.  2 阶
> 
> 
> 输入： 3
> 输出： 3
> 解释： 有三种方法可以爬到楼顶。
> 1.  1 阶 + 1 阶 + 1 阶
> 2.  1 阶 + 2 阶
> 3.  2 阶 + 1 阶
> ```

> 考虑hash，缓存，定义私有成员 `int* sum`, 在构造函数中 `new int [nums.size() + 1]` 数组来缓存 `0 - i`  的和，最终要求出 `i ~ j`  之间的数组和只需要 `return sum[j + 1] - sum[i]` 
>
> 对于为何要 `num.size() + 1` ，因为若是求 `0 ~ j`, 按`new int [num.size()]` 算的话，最终应该是 `return sum[j] - sum[i - 1];`, 越界报错。所以添加一个虚拟的 `0`

## [392. 判断子序列](https://github.com/artintel/LeetCode/blob/master/392.%20%E5%88%A4%E6%96%AD%E5%AD%90%E5%BA%8F%E5%88%97/source_code.cpp)

> 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
>
> 你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。
>
> 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
>
> 示例 1:
> s = "abc", t = "ahbgdc"
>
> 返回 true.
>
> 示例 2:
> s = "axc", t = "ahbgdc"
>
> 返回 false.
>
> 后续挑战 :
>
> 如果有大量输入的 S，称作S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？
>

> `stack`保存`s`，倒序遍历 `t`,每当匹配，`stack.pop()`,最后判断 `stack.empty()?`，空即为子序列，反之不然

> DP动态规划：
>
> 可以将此题看错 最大公共子序列的变种 定义`dp[s.length() + 1][t.length() + 1]`
>
> for双重循环遍历数组
>
> 如果`s[i] == t[j], dp[i][j] = dp[i - 1][j - 1];`
>
> 否则`dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);`

## [628. 三个数的最大乘积](https://github.com/artintel/LeetCode/blob/master/628.%20%E4%B8%89%E4%B8%AA%E6%95%B0%E7%9A%84%E6%9C%80%E5%A4%A7%E4%B9%98%E7%A7%AF/source_code.cpp)

> 给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。

> ```
> 输入: [1,2,3]
> 输出: 6
> ```

## [643. 子数组最大平均数](https://github.com/artintel/LeetCode/blob/master/643.%20%E5%AD%90%E6%95%B0%E7%BB%84%E6%9C%80%E5%A4%A7%E5%B9%B3%E5%9D%87%E6%95%B0/source_code.cpp)

> 给定 `n` 个整数，找出平均数最大且长度为 `k` 的连续子数组，并输出该最大平均数。

> ```
> 输入: [1,12,-5,-6,50,3], k = 4
> 输出: 12.75
> 解释: 最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
> ```

> 滑动窗口，k 大小的窗口数组在`nums()`数组上滑动，找到和最大窗口

## [10. 正则表达式匹配](https://github.com/artintel/LeetCode/blob/master/10.%20%E6%AD%A3%E5%88%99%E8%A1%A8%E8%BE%BE%E5%BC%8F%E5%8C%B9%E9%85%8D/source_code.cpp)

> 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
>
> - '.' 匹配任意单个字符
>
> - '*' 匹配零个或多个前面的那一个元素
>
> 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

> ```
> 输入：s = "aa" p = "a"
> 输出：false
> 解释："a" 无法匹配 "aa" 整个字符串。
> 
> 
> 输入：s = "aa" p = "a*"
> 输出：true
> 解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
> 
> 
> 输入：s = "ab" p = ".*"
> 输出：true
> 解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
> 
> 输入：s = "aab" p = "c*a*b"
> 输出：true
> 解释：因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
> 
> ```

> 动态规划的思想，注意状态的更换

## [661. 图片平滑器](https://github.com/artintel/LeetCode/blob/master/661.%20%E5%9B%BE%E7%89%87%E5%B9%B3%E6%BB%91%E5%99%A8/source_code.cpp)

> 包含整数的二维矩阵 M 表示一个图片的灰度。你需要设计一个平滑器来让每一个单元的灰度成为平均灰度 (向下舍入) ，平均灰度的计算是周围的8个单元和它本身的值求平均，如果周围的单元格不足八个，则尽可能多的利用它们。
>

> ```
> 输入:
> [[1,1,1],
>  [1,0,1],
>  [1,1,1]]
> 输出:
> [[0, 0, 0],
>  [0, 0, 0],
>  [0, 0, 0]]
> 解释:
> 对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
> 对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
> 对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
> ```

> 类似深度学习神经网络里的 kernel

## [11. 盛最多水的容器](https://github.com/artintel/LeetCode/blob/master/11.%20%E7%9B%9B%E6%9C%80%E5%A4%9A%E6%B0%B4%E7%9A%84%E5%AE%B9%E5%99%A8/source_code.cpp)

> 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
>

> ```
> 输入：[1,8,6,2,5,4,8,3,7]
> 输出：49 
> 在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
> ```

> 双指针法：

## [15. 三数之和](https://github.com/artintel/LeetCode/blob/master/11.%20%E7%9B%9B%E6%9C%80%E5%A4%9A%E6%B0%B4%E7%9A%84%E5%AE%B9%E5%99%A8/source_code.cpp)

> 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
>
> 注意：答案中不可以包含重复的三元组。
>

> ```
> 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
> 
> 满足要求的三元组集合为：
> [
>   [-1, 0, 1],
>   [-1, -1, 2]
> ]
> ```

> 排序以及三重循环

