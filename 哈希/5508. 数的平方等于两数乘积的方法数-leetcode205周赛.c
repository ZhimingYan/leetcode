#include "uthash/uthash.h"

typedef struct myHash {
    int key;
    int val;
    UT_hash_handle hh;
} Hash;

Hash *g_hash = NULL;


void AddHash(int a) {
    Hash *p = NULL;
    HASH_FIND_INT(g_hash, a, p);
    if (p == NULL) {
        p = malloc(sizeof(Hash));
        p->key = a;
        p->val = 1;
        HASH_ADD_INT(g_hash, key, p);
    } else {
        p->val++;
    }    
}


void Match(int nums1, int nums1Size, int *numsm2, int nums2Size)
{
    for (int i = 0; i < nums1Size; i++) {
        AddHash(nums1[i] * nums1[i]);
    }
    int count = 0;
    for (int i = 0; i < nums2Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            Hash *p = NULL;
            HASH_FIND_INT(g_hash, numsm2[i] * numsm2[j], p);
            if (p == NULL) {
                continue;
            }
            count++;

        }
    }
    return count;

}

int numTriplets(int* nums1, int nums1Size, int* nums2, int nums2Size){
    return Match(nums1, nums1Size, nums2, nums2Size) + Match(nums2, nums2Size, nums1, nums1Size);
}