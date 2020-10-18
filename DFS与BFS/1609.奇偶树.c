/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAXLEN 100000
struct TreeNode* queue[MAXLEN];
int head;
int tail;

bool BFS(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    bool desc = false;
    queue[tail++] = root;
    while (head != tail) {
        int scop = tail - head;
        int cur  = desc ? INT_MAX : -1;
        int pre = desc ? INT_MAX : -1;
        for (int i = 0; i < scop; i++) {
            struct TreeNode* tmp = queue[head++];
            cur = tmp->val;
            if (cur%2 == 1 && desc) {
            return false;
        }
        if (cur%2 == 0 && !desc) {
            return false;
        }
        if (cur==pre || (cur > pre && desc) || (cur < pre && !desc)) {
            return false;
        }
        if (tmp->left) {
            queue[tail++] = tmp->left;
        }
        if (tmp->right) {
            queue[tail++] = tmp->right;
        }
        pre = cur;
        }
        desc = !desc;
    }
    return true;
}

bool isEvenOddTree(struct TreeNode* root){
    memset(queue, 0, sizeof(struct TreeNode*));
    tail = 0;
    head = 0;
    return BFS(root);
}