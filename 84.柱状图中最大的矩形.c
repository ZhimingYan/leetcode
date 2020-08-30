/*
 * @lc app=leetcode.cn id=84 lang=c
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start


#include <stdio.h>
#define MAX_STACK_LEN 50000

int g_stack[MAX_STACK_LEN];
int g_stackLen;

int GetMax(int a, int b) 
{
    if(a >= b) {
        return a;
    }
    return b;
}

void InitStack() 
{
    g_stack[0] = -1;
    g_stackLen = 1;

}

int largestRectangleArea(const int* heights, int heightsSize)
{
    int maxArea = 0;
    int area;
    int stackIndex;
    InitStack();
    if (heightsSize >= MAX_STACK_LEN) {
        return -1;
    }
    for (int i = 0; i < heightsSize; i++) {
        //不满足单调递增，则计算面积并出栈
        while ((g_stack[g_stackLen - 1] >= 0) && (heights[i] < heights[g_stack[g_stackLen - 1]])) {
            area = ((i - g_stack[g_stackLen - 1 - 1]) - 1) * heights[g_stack[g_stackLen - 1]];
            maxArea = GetMax(maxArea,area);
        // Pop
        g_stackLen--;
        }
        //满足单调递增，入栈
        g_stack[g_stackLen++] = i;
    }
    //最后对栈内元素进行特殊的处理，计算面积
    stackIndex = g_stack[g_stackLen - 1];
    while (g_stackLen > 1) {
        area = (stackIndex - g_stack[g_stackLen - 1 - 1]) * heights[g_stack[g_stackLen - 1]];
        maxArea = GetMax(maxArea, area);

        //Pop
        g_stackLen--;
    }
    return maxArea;

}

// @lc code=end

