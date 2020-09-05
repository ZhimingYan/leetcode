/*
 * @lc app=leetcode.cn id=508 lang=c
 *
 * [508] 出现次数最多的子树元素和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXNN 100000

typedef struct myHash {
    int key;
    int val;
    UT_hash_handle hh;
} Hash;

Hash *g_hash = NULL;

void AddHash(int a)
{
    Hash *s = NULL;
    HASH_FIND_INT(g_hash, &a, s);
    if (s != NULL) {
        s->val++;
        return;
    }
    s = (Hash *)malloc(sizeof(Hash));
    s->key = a;
    s->val = 1;
    HASH_ADD_INT(g_hash, key, s);
}

void DelHash()
{
    Hash *s = NULL;
    Hash *tmp = NULL;
    HASH_ITER(hh, g_hash, s, tmp) {
        HASH_DEL(g_hash, s);
        free(s);
    }
}

int cmp(Hash *a, Hash *b)
{
    return (b->val - a->val);//从大到小
}

void SortHash()
{
    HASH_SORT(g_hash, cmp);
}

int dfs(struct TreeNode *root){
    if(root == NULL) {
        return 0;
    }
    int leftSum = dfs(root->left);
    int rightSum = dfs(root->right);
    int sum = leftSum + rightSum + root->val;
    AddHash(sum);
    return sum;
}

int* findFrequentTreeSum(struct TreeNode* root, int* returnSize){
    g_hash = NULL;
    dfs (root);
    SortHash();
    int *res = (int *)malloc(sizeof(int) * MAXNN);
    memset(res, 0, sizeof(int) * MAXNN);
    Hash *s = NULL;
    Hash *tmp = NULL;
    int index = 0;
    int pre =  -1;
    HASH_ITER(hh, g_hash, s, tmp) {
        if (index == 0) {
            res[index++] = s->key;
            pre = s->val;
            continue;
        }
        if (s->val == pre) {
            res[index++] = s->key;
            continue;
        }
        break;
    }
    *returnSize = index;
    return res;
}



// @lc code=end

