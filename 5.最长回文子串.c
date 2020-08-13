/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include<stdbool.h>
#define N 1001
char g_res[N];
int min(int a, int b)
{
    if (a <= b) {
        return  a;
    }
    return b;
} 

int max(int a, int b)
{
    if (a >= b) {
        return  a;
    }
    return b;
} 

bool IsPalindrom(char *s, int left , int right) 
{
    while (left < right)
    {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;

}

bool IsPalindrom2(char *s, int left , int right) 
{
    if ((left == right) || ((right - left == 1) && (s[left] == s[right]))) {
        return true;
    }
    if (left > right) {
        return false;
    }

    return IsPalindrom(s, left + 1, right - 1);
}

typedef struct 
{
    int left;
    int right;
    int gap;
}Bound;


char * longestPalindrome(char * s){
    int len = strlen(s);
    int left, right;
    Bound bound = { 0 };
    for (int i = 1; i < len; i++) {
        for (left = i - 1, right = i + 1; left >= 0 && right < len; left-- , right++) {
            if (IsPalindrom2(s, left, right)) {
                if (right - left > bound.gap) {
                    bound.right = right;
                    bound.left = left;
                    bound.gap = right - left;
                } else {
                   continue;
                }
            }
        }
    }

    for (int i = 0; i < len; i++) {
        for (left = i, right = i + 1; left >= 0 && right < len; left--, right++) {
            if (IsPalindrom2(s, left, right)) {
                if (right - left > bound.gap) {
                    bound.right = right;
                    bound.left = left;
                    bound.gap = right - left;
                } else
                {
                    continue;
                }
            }
        }
    }

    int index = 0;
    for ( int i = bound.left ; i <= bound.right; i++) {
        g_res[index++] = s[i];
    }
    g_res[index] = '\0';

    return g_res;
}


// @lc code=end

