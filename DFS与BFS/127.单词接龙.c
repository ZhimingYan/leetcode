/*
 * @lc app=leetcode.cn id=127 lang=c
 *
 * [127] 单词接龙
 */

// @lc code=start

#include <stdbool.h>
#define MAX_QUEUE_LEN 100000

static bool IsMatch(const char *word1, const char *word2)
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    if (len1 != len2) {
        return false;
    }
    int count = 0;
    for (int i = 0 ; i < len1; i++) {
        if (word1[i] != word2[i]) {
            count++;
        }
    }
    if (count == 1) {
        return true;
    }
    return false;
}

static bool IsInWordList(char *word, char ** wordList, int wordSize) {
    int i = 0;
    while (i < wordSize) {
        if (strcmp(word, wordList[i]) == 0) {
            break;
        }
        i++;
    }
    if (i == wordSize) {
        return false;
    }
    return true;
}

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    char *queue[MAX_QUEUE_LEN] = {0};
    int head = 0;
    int tail = 0;
    if (!IsInWordList(endWord, wordList, wordListSize)) {
        return 0;
    }
    int *mark = (int *)malloc(wordListSize * sizeof(int));
    //uint32_t rc = memset_s(mark, sizeof(queue), 0, sizeof(queue));
    memset(mark, 0,wordListSize * sizeof(int));
    queue[tail++] = beginWord;
    int step = 1;
    while (head != tail) {
        int scop = tail - head;
        for (int i = 0; i < scop; i++) {
            char *temp = queue[head++]; 
            if (strcmp(temp, endWord) == 0) {
                free(mark);
                return step;
            }
            for (int j = 0; j < wordListSize; j++) {
                if ((mark[j] == 0) && IsMatch(temp, wordList[j])) {
                    mark[j] = 1;
                    queue[tail++] = wordList[j];
                }
            }
        }
        step++;
    }
    free(mark);
    return 0;
}

// @lc code=end

