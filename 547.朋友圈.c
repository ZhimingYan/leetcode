/*
 * @lc app=leetcode.cn id=547 lang=c
 *
 * [547] 朋友圈
 */

// @lc code=start
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define MAX_NN 40000;
int g_student[MAX_NN];
int g_len;

bool MallocSize(int** M, int MSize)
{
    if (MSize == 0) {
        return false;
    }
    M = (int **) malloc(MSize * sizeof(int *));
    if (M == NULL) {
        return false;
    }
    
    for (int i = 0; i < MSize; i++) {
        M[i] = (int *)malloc(M[0] * sizeof(int));
        if (M[i] == NULL) {
            return false;
        }
    }

    g_len = MSize * MSize;
    return true;

}

void Init(int **M, int MSize)
{
    int index = 0;
    for (int i = 0; i < MSize; i++) {
        for (int j = 0; j < MSize; j++) {
            int index = i * MSize + j;
            g_student[index] = index;
        }
    }
}

int Find(int x) 
{
    if (g_student[x] != x) {
        return Find(g_student[x]);
    }
    return x;
}


int findCircleNum(int** M, int MSize, int* MColSize){

}


// @lc code=end

