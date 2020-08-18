/*
 * @lc app=leetcode.cn id=227 lang=c
 *
 * [227] 基本计算器 II
 */

// @lc code=start
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 1000000

int calculate(char * s) {
    int stack[N] = {0};
    int stackLen = 0;
    char tmp[N] = {0};
    int len = strlen(s);
    int index = 0;
    for (int i = 0; i < len; i++) {
        if(isspace(s[i])) {
            continue;
        }
        tmp[index++] = s[i];
    }
    tmp[index] = '\0';

    int tmpLen = strlen(tmp);

    int num = 0;
    char sign = '+';
    for (int i = 0; i < tmpLen; i++) {
        char c = tmp[i];
        if (isdigit(c)) {
            num = 10 * num + (c - '0');
        }
        if (!isdigit(c) || (i == tmpLen - 1)) {
            switch (sign) {
                int pre;
                case '+':
                    stack[stackLen++] = num;
                    break;
                case '-':
                    stack[stackLen++] = -num;
                    break;
                case '*':
                    pre = stack[--stackLen];
                    stack[stackLen++] = pre * num;
                    break;
                case '/':
                    pre = stack[--stackLen];
                    stack[stackLen++] = pre / num;
                    break;

            }
            sign = c;
            num = 0;
        }
    }
    int res = 0;
    for (int i = 0; i < stackLen; i++) {
        res += stack[i];
    }
    return res;
}
// @lc code=end 

