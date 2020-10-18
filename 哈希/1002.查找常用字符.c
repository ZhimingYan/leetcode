/*
 * @lc app=leetcode.cn id=1002 lang=c
 *
 * [1002] 查找常用字符
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAXLEN 100
char ** commonChars(char ** A, int ASize, int* returnSize){
    int hash1[26] = {0};
    int hash2[26] = {0};

    for (int j = 0; j < strlen(A[0]); j++) {
        hash1[A[0][j] - 'a']++;
    }
    for (int i = 1; i < ASize; i++) {
        for (int j = 0; j < strlen(A[i]); j++) {
            if (hash1[A[i][j] - 'a'] != 0) {
                hash2[A[i][j] - 'a']++;
                hash1[A[i][j] - 'a']--;
            }
        }
       
        for (int k = 0; k < 26; k++) {
            hash1[k] = hash2[k];
        }
        memset(hash2, 0, sizeof(hash2));
    }

    char** res = (char **)malloc(sizeof(char *) * MAXLEN);
    int index = 0;

    if (ASize == 1) {
        for (int k = 0; k < 26; k++) {
            if (hash1[k] != 0) {
                res[index] = (char *)malloc(sizeof(char) * 2);
                res[index][0] = 'a' + k;
                res[index][1] = '\0';
                index++;
            }
        }
        *returnSize = index;
        return res;
    }
    for (int k = 0; k < 26; k++) {
        while (hash1[k] != 0) {
            res[index] = (char *)malloc(sizeof(char) * 2);
            res[index][0] = 'a' + k;
            res[index][1] = '\0';
            hash1[k]--;
            index++;
        }
    }

    *returnSize = index;
    return res;

}

// @lc code=end

