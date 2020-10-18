/*
 * @lc app=leetcode.cn id=763 lang=c
 *
 * [763] 划分字母区间
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int res[500] = {0};
int len;

void dfs(char *s, int l , int r)
{
    if (l > r) {
        return;
    }

    int last = r;
    // 从后向前找到第一个与最左边的相同的数 并记录
    while(last > l && s[last] != s[l]) {
        last--;
    } 
    for (int i = l; i <= last; i++) {
        //如果当前到了与左边第一个相等的函数，那么就结束循环 下一次为last + 1 到 r
        if (i == last) {
            res[len++] = last - l + 1;
            break;
        }
        //如果还没到，就中找到
        int j = r;
        while(i != j && s[i] != s[j]) {
            j--;
        }
        last = j > last ? j : last;
    }
    dfs (s, last + 1, r);
}

int* partitionLabels(char * S, int* returnSize){
    len = 0;
    memset(res, 0, sizeof(res));
    if (S == NULL) {
        *returnSize = 0;
        return res;
    }
    if (strlen(S) == 1) {
        res[0] = 1;
        *returnSize = 1;
        return res;
    }
    
    int l = 0;
    int r = strlen(S) - 1;
    dfs(S, l, r);
    *returnSize = len;
    return res;
}
// @lc code=end

