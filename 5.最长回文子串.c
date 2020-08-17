/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */

// @lc code=start
void help(char *s, int N, int left, int right, int *start, int *len) {
    while (left >= 0 && right < N && s[left] == s[right])
        left--, right++;
    if (right - left - 1 > *len) {  // 如果找到更长的子串，保存其信息
        *start = left + 1;
        *len = right - left - 1;
    }
}
char * longestPalindrome(char * s){
    int N = strlen(s), start = 0, len = 0;  // N 字符串长度， start 子串起始位置， len 子串长度
    for (int i = 0; i < N; i++)     // 奇数长度的回文子串
        help(s, N, i-1, i+1, &start, &len);
    for (int i = 0; i < N; i++)     // 偶数长度的回文子串
        help(s, N, i, i+1, &start, &len);
    s[start + len] = '\0';          // 原地修改返回
    return s + start;
}


// @lc code=end

