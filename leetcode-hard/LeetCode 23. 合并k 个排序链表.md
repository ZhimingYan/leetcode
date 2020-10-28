## LeetCode 23. 合并$k$ 个排序链表

**[原题链接](https://leetcode.com/problems/merge-k-sorted-lists/description/) 【hard】** 

#### 题目描述

合并$k$ 个有序的单向链表

链表节点的数据结构：

~~~cpp
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
~~~

#### 算法

**(二分治合并)** $O(nlogk)$ 

- 将所有待合并的有序单向链表进行递归分治处理，即将当前链表的序列分成两部分，每部分递归进行合并，然后将当前左右两部分合并的结果再进行 二合并 即可。

**时间复杂度**

- 递归每层的时间复杂度是整个节点个数$O(n)$ , 由于每次是二分，所以总共有$O(logk)$ 层。故总的时间复杂度为$O(nlogk)$. 

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
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        while (l1 != NULL && l2 != NULL) {
            if (l1 -> val < l2 -> val) {
                cur -> next = l1;
                l1 = l1 -> next;
            }
            else {
                cur -> next = l2;
                l2 = l2 -> next;
            }
            cur = cur -> next;
        }
        cur -> next = (l1 != NULL ? l1 : l2);
        return head -> next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];

        int mid = lists.size() / 2;
        vector<ListNode*> left = vector<ListNode*>(lists.begin(), lists.begin() + mid);
        vector<ListNode*> right = vector<ListNode*>(lists.begin() + mid, lists.end());
        ListNode *l1 = mergeKLists(left);
        ListNode *l2 = mergeKLists(right);
        return merge2Lists(l1, l2);
    }
};
~~~

