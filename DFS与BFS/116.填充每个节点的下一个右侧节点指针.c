/*
 * @lc app=leetcode.cn id=116 lang=c
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
    if (root == NULL) {
        return root;
    }

    // 初始化队列同时将第一层节点加入队列中，即根节点
    struct Node* Q[5000];
    int left = 0, right = 0;
    Q[right++] = root;

    // 外层的 while 循环迭代的是层数
    while (left < right) {
        // 记录当前队列大小
        int size = right - left;

        // 遍历这一层的所有节点
        for (int i = 0; i < size; i++) {
            // 从队首取出元素
            struct Node* node = Q[left++];

            // 连接
            if (i < size - 1) {
                node->next = Q[left];
            }

            // 拓展下一层节点
            if (node->left != NULL) {
                Q[right++] = node->left;
            }
            if (node->right != NULL) {
                Q[right++] = node->right;
            }
        }
    }

    // 返回根节点
    return root;
}

// @lc code=end

