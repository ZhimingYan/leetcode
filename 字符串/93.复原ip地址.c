/*
 * @lc app=leetcode.cn id=93 lang=c
 *
 * [93] 复原IP地址
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <string.h>

int str2int(char* start, char* end) {
    if (*start == '0' && end != start) {
        return 256;
    }
    char* current = start;
    int ret = 0;
    while (current <= end) {
        ret *= 10;
        ret += (*current - '0');
        current++;
    }
    return ret;
}

void findNextPart(char* s, int num, int result[][4], int* retSize)
{
    int l = strlen(s);
    if (l > num * 3 || l < num) {
        return;
    }
    if (num == 1) {
        char* end = s;
        while (*end != '\0') {
            end++;
        }
        int part = str2int(s, end - 1);
        if (part <= 255) {
            result[*retSize][3] = part;
            for (int i = 0; i < 4; i++) {
                result[*retSize + 1][i] = result[*retSize][i];
            }
            *retSize += 1;
        }
        return;
    } else {
        char* end = s;
        int part = str2int(s, end);
        while (part <= 255 && *(end + 1) != '\0' && end - s < 3) {
            result[*retSize][4- num] = part;
            findNextPart(end + 1, num - 1, result, retSize);
            end++;
            part = str2int(s, end);
        }
    }
}

char ** restoreIpAddresses(char * s, int* returnSize){
    int result[100][4];
    *returnSize = 0;
    findNextPart(s, 4, &result, returnSize);
    char** resultArr = (char**)malloc(sizeof(char*) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        resultArr[i] = (char*) malloc(sizeof(char) * (strlen(s) + 4));
        sprintf(resultArr[i], "%d.%d.%d.%d", result[i][0], result[i][1], result[i][2], result[i][3]);
        resultArr[i][strlen(s) + 3] = 0;
    }
    return resultArr;
}


// @lc code=end

