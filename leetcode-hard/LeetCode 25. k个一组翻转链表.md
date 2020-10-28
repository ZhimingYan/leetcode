## LeetCode 25. $k$ 个一组翻转链表

**[原题链接](https://leetcode.com/problems/reverse-nodes-in-k-group/description/) 【hard】** 

#### 题目描述

给你一个链表，每 $k$ 个节点一组进行翻转，请你返回翻转后的链表。

$k $是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 $k$的整数倍，那么请将最后剩余的节点保持原有顺序。

**示例：**

~~~
给你这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5
~~~

**说明：** 

- 你的算法只能使用常数的额外空间。
- 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

#### 算法

**(模拟）** $O(L)$ 

延续 [Swap Nodes in Pairs](https://www.acwing.com/solution/leetcode/content/72/) 的思路：

- 增加虚拟头结点 dummy，并且令 cur 指针指向 dummy。
2. 对于每一轮的修改，令 `first` 指针为 `cur->next`，并求出 `end `指针为下一轮需要交换的最后一个结点；在找 `end` 的过程中，若不足 `k` 个结点，则直接终止循环。
3. 在找到 `first` 和 `end` 后，设置 `p1` 和 `p2` 两个指针修改相邻结点之间的连接关系，需要一个临时的 `new_p2` 指针。（参考代码）
4. 最终修改 `cur->next` 和 `first->next`。
5. 令 `cur` 指向下一轮修改的起始位置的前一个位置。

**时间复杂度**

- $O(L)$

**空间复杂度**

- 常数空间

**C++代码**

~~~cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;

        while (cur != NULL) {
            ListNode *first = cur->next;
            ListNode *end = cur;

            for (int i = 0; i < k && end != NULL; i++)
                end = end->next;

            if (end == NULL)
                break;

            ListNode *p1 = first;
            ListNode *p2 = first->next;

            while (p1 != end) {
                ListNode *new_p2 = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = new_p2;
            }

            first->next = p2;
            cur->next = end;
            cur = first;
        }
        return dummy->next;
    }
};
~~~

