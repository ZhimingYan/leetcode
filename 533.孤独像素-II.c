#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <securec.h>
#include <uthash.h>

typedef struct _hash_st {
    char *key;
    int val;
    UT_hash_handle hh;
}hash_st;

int findBlackPixel(char** picture, int pictureSize, int* pictureColSize, int N){
    int row = pictureSize;
    int col = pictureColSize[0];

    //记录每行的B个数
    int *row_cnt = (int *)calloc(row, sizeof(int));
    //记录每列的B个数
    int *col_cnt = (int *)calloc(col, sizeof(int));
    //记录每行的pattern编号
    int *pattern = (int *)calloc(row, sizeof(int));

    hash_st *head = NULL;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(picture[i][j] == 'B') {
                row_cnt[i]++;
                col_cnt[j]++;
            }
        }

        char *key = picture[i];

        hash_st *tmph;
        HASH_FIND(hh, head, key, col, tmph);
        if(tmph == NULL) {
            tmph = (hash_st *)calloc(1, sizeof(hash_st));
            tmph->key = key;
            tmph->val = i;

            HASH_ADD_KEYPTR(hh, head, tmph->key, col, tmph);
        }

        pattern[i] = tmph->val;
    }
/*
    for(int i = 0; i < row; i++) {
        printf("row_cnt[%d] = %d    ", i, row_cnt[i]);
    }
    printf("\n");

    for(int j = 0; j < col; j++) {
        printf("col_cnt[%d] = %d    ", j, col_cnt[j]);
    }
    printf("\n");

    for(int i = 0; i < row; i++) {
        printf("pattern[%d] = %d    ", i, pattern[i]);
    }
    printf("\n");
*/
    int ret = 0;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(picture[i][j] != 'B' || row_cnt[i] != N || col_cnt[j] != N) {
                continue;
            }

            //printf("i = %d, j = %d\n", i, j);

            int cnt = 0;
            for(int k = 0; k < row; k++) {
                if(picture[k][j] != 'B' || pattern[k] != pattern[i]) {
                    continue;
                }

                cnt++;
            }

            ret += cnt == N? 1 : 0;
        }
    }

    return ret;
}