int cmp (const void *_a, const void *_b)
{
    int *a = (int *)_a;
    int *b = (int *)_b;
    return *a - *b;
}

int specialArray(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);

    for (int j = 0; j <= numsSize; j++) {
        int count = 0;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] >= j) {
                count++;
            }
        }
        if (count == j) {
            return j;
        }
    }
    return -1;
}