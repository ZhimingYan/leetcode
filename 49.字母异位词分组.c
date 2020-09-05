/*
 * @lc app=leetcode.cn id=49 lang=c
 *
 * [49] 字母异位词分组
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct {
    char *key;
    char **words;
    int size;
    int capacity;
    UT_hash_handle hh;
} Hash;

Hash *g_hash = NULL;

int cmp(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}

void AddHash(char *s)
{
    int len = strlen(s);
    char *tmp = (char *)malloc((len + 1) * sizeof(char));
    if (tmp == NULL) {
        return;
    }
    strcpy(tmp, s);
    qsort(tmp, len, sizeof(char), cmp);
    Hash *p = NULL;
    HASH_FIND(hh, g_hash, tmp, len, p);
    if (p == NULL) {
        p = malloc(sizeof(Hash));
        p->key = tmp;
        p->capacity = 10;
        p->size = 0;
        p->words = (char **)malloc(p->capacity * sizeof(char *));
        if (p->words == NULL) {
            return;
        }
        HASH_ADD_STR(g_hash, key, p);
    } else if (p->capacity == p->size) {
        p->capacity *= 2;
        p->words = realloc(p->words, p->capacity * sizeof(char *));
    }
    p->words[p->size++] = s;

}

void FreeHash()
{
    Hash *cur = NULL;
    Hash *tmp = NULL;
    HASH_ITER(hh, g_hash, cur, tmp) {
        HASH_DEL(g_hash, cur);
        free(cur);
    }
    return;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    g_hash = NULL; 
    for (int i=0; i<strsSize; ++i) {
        AddHash(strs[i]);
    }
    int size = 0;
    *returnSize = HASH_COUNT(g_hash);
    char ***res = (char ***)malloc(*returnSize * sizeof(char**));
    if (res == NULL) {
        return NULL;
    }
    *returnColumnSizes = (int *)malloc(*returnSize * sizeof(int));
    if (returnColumnSizes == NULL) {
        return NULL;
    }
    Hash *cur = NULL;
    Hash *tmp = NULL;
    HASH_ITER(hh, g_hash, cur, tmp) {
        res[size] = cur->words;
        (*returnColumnSizes)[size] = cur->size;
        ++size;
    }
    FreeHash
    return res;
}
// @lc code=end

