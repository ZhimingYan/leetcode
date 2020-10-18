/*
 * @lc app=leetcode.cn id=451 lang=c
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start

typedef  struct tagHash {
    int key;
    int count;
    UT_hash_handle hh;
} Hash;

Hash *g_hash = NULL;

void InsertNode(int key) {
    Hash *s = NULL;
    HASH_FIND_INT(g_hash, &key, s);

    if (s == NULL) {
        s = (Hash *)malloc(sizeof(Hash));
        s->key = key;
        s->count = 1;
        HASH_ADD_INT(g_hash, key, s);
    } else {
        s->count++;
    }
    return;
}

void FreeAll()
{
    Hash *cur, *tmp;
    HASH_ITER(hh, g_hash, cur, tmp) {
        HASH_DEL(g_hash, cur);
        free(cur);
    }
    return;
}
// HASH_SORT比较函数，这里是根据字符出现频率降序排列
int cmp(Hash *a, Hash *b)
{
    return a->count > b->count;
}

char * frequencySort(char * s){
    char *p = s;
    char *res = (char *)malloc(strlen(s) + 1);
    res[strlen(s)] = '\0';
    while (*p) {
        InsertNode(*p);
        p++;
    } 
    HASH_SORT(g_hash, cmp);

    int index = 0;
    Hash *cur, *tmp;
    HASH_ITER(hh, g_hash, cur, tmp) {
        for (int i = 0; i < cur->count; i ++) {
            res[index] = cur->key;
            index++;
        }
    }

    FreeAll();
    return res;
}




// @lc code=end

