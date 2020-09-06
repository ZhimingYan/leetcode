typedef struct myHash {
    long key;
    int val;
    UT_hash_handle hh;
} Hash;

Hash *g_hash = NULL;


void AddHash(long a) {
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
void FreeAll()
{
    Hash *cur, *tmp;
    HASH_ITER(hh, g_hash, cur, tmp) {
        HASH_DEL(g_hash, cur);
        free(cur);
    }
    return;
}

int Match(int *nums1, int nums1Size, int *numsm2, int nums2Size)
{
    if (nums1Size == 1) {
        return 0;
    }
    g_hash = NULL;
    long tmp = 0;
    for (int i = 0; i < nums1Size; i++) {
        tmp = (long)nums1[i]*nums1[i];
        AddHash(tmp);
    }
    int count = 0;
    for (int i = 0; i < nums2Size; i++) {
        for (int j = i + 1; j < nums2Size; j++) {
            Hash *p = NULL;
            long tmp2 = (long)numsm2[i] * numsm2[j];
            HASH_FIND_INT(g_hash, &tmp2, p);//uthash没有long类型么
            int a = (int )tmp2;
            if (nums1Size == 1) {
                printf("%ld" ,tmp2);
            }
            if (p == NULL) {
                continue;
            }
            count += p->val;
        }
    }
    FreeAll();
    printf("%d\n" , count);
    return count;

}



int numTriplets(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int res = Match(nums1, nums1Size, nums2, nums2Size) + Match(nums2, nums2Size, nums1, nums1Size);
    
    return res;
}