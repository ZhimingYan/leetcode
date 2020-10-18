#define MAXN 500000

typedef struct tagHash {
    int key;
    int val;
    UT_hash_handle hh;
} Hash;

Hash *g_hash;

void AddHash(int a)
{
    Hash *p = NULL;
    HASH_FIND_INT(g_hash, &a, p);
    if (p == NULL) {
        p = (Hash *)malloc(sizeof(Hash));
        p->key = a;
        p->val = 1;
        HASH_ADD_INT(g_hash, key, p);
    } else {
        p->val++;
    }
}

void FreeHash()
{
    Hash *cur = NULL;
    Hash *tmp = NULL;
    HASH_ITER(hh, g_hash, cur, tmp) {
        HASH_DEL(g_hash, cur);
        free(cur);
    }
}

int cmp(Hash *a, Hash *b)
{
    return a->val < b->val;
}

int FindFirst(int *nums, int numsSize, int key) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == key) {
            return i;
        }
    }
    return -1;
}

int FindLast(int *nums, int numsSize, int key) {
    for (int i = numsSize - 1 ; i >= 0; i--) {
        if (nums[i] == key) {
            return i;
        }
    }
    return -1;
}

int Min(int x, int y) {
    return x < y ? x : y;
}

int findShortestSubArray(int* nums, int numsSize){
    g_hash = NULL;
    
    for (int i = 0; i < numsSize; i++) {
        AddHash(nums[i]);
    }

    HASH_SORT(g_hash, cmp);

    Hash *cur = NULL;
    Hash *tmp = NULL;
    int preVal = -1;
    int cout = 1;
    int res = MAXN;
    HASH_ITER(hh, g_hash, cur ,tmp) {
        if (cout++ == 1 ) {
            preVal = cur->val;
        }
        if (preVal != cur->val) {
            break;
        }
        
        int first = FindFirst(nums, numsSize, cur->key);
        int last = FindLast(nums, numsSize, cur->key);
        res = Min(last - first + 1, res);
    }

    return res;


}