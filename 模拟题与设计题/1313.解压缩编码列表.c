#define MAXLEN 1000001
int* decompressRLElist(int* nums, int numsSize, int* returnSize){
    int * res = (int *)malloc(sizeof(int) * MAXLEN);
    memset(res, 0, sizeof(int) * MAXLEN);
    
    int index = 0;
    for (int i = 0; i < numsSize; i+=2) {
        for (int j = 0; j < nums[i]; j ++) {
            res[index++] = nums[i+1];
        }
    }
    
    *returnSize = index;
    return res;
}
