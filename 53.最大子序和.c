/*
 * @lc app=leetcode.cn id=53 lang=c
 *
 * [53] 最大子序和
 */

// @lc code=start



int GetMax(int a, int b)
{
    return a > b? a : b;
}

int maxSubArray(int* nums, int numsSize){
    int *sum = (int *)malloc((numsSize + 1) * sizeof(int));
    if (sum == NULL) {
        return 0;
    }
    memset(sum, 0, (numsSize + 1) * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        sum[i + 1] = sum[i] + nums[i];
    }
    int res = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j <= i; j++) {
            res = GetMax(res, sum[i + 1] - sum[j]);
        }
    }
    return res;
}


// @lc code=end

