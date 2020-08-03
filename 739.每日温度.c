/*
 * @lc app=leetcode.cn id=739 lang=c
 *
 * [739] 每日温度
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define MAX_DAILY_TEMPERATURE_NUM 30010
int *g_destStack;
int g_destLen;
int g_tempStack[MAX_DAILY_TEMPERATURE_NUM];
int g_tempLen;

int GetMax(int a, int b)
{
    if (a >= b) {
        return a;
    }
    return b;
}

bool MallocDailyTemperatures(int* t, int tSize)
{
    int i;
    g_destLen = 0;
    if (tSize == 0) {
        return false;
    }
    g_destStack = (int *)malloc(tSize * sizeof(int));
    if (g_destStack == NULL) {
        return false;
    }

    for (i = 0; i < tSize; i++) {
        g_destStack[i] = 0;
    }

    return true;
}


int* dailyTemperatures(int* T, int TSize, int* returnSize) 
{
    int i;
    int stackIndex;
    bool rslt;
    g_tempLen = 0;
    rslt = MallocDailyTemperatures(T, TSize);
    if (!rslt) {
        (*returnSize) = 0;
        return NULL;
    }
    g_tempStack[0] = 0;
    g_tempLen++;

    for (int i = 1; i < TSize; i++) {
        while (g_tempLen > 0) {
            stackIndex = g_tempStack[g_tempLen - 1]; // 栈顶元素
            // 不满足单调递减
            if (T[i] > T[stackIndex]) {
                g_destStack[stackIndex] = i - stackIndex;

                // 出栈
                g_tempLen--;
                continue;
            }
            break;
        }
        // 满足单调递减
        g_tempStack[g_tempLen++] = i;
    }

    (*returnSize) = TSize;
    return g_destStack;
}


// @lc code=end

