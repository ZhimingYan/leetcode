/*
 * @lc app=leetcode.cn id=560 lang=c
 *
 * [560] 和为K的子数组
 */

// @lc code=start


int subarraySum(int* nums, int numsSize, int k){
    int res = 0;

    int* sumHash = (int *)malloc((numsSize+1) * sizeof(int));

    memset(sumHash,0,sizeof(sumHash));
    for (int i = 0; i < numsSize; i++) {
        sumHash[i + 1] = sumHash[i] + nums[i];
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j = 0 ; j <= i; j++) {
            int disSum = sumHash[i+1] - sumHash[j]; 
            if (disSum == k) {
                res++;
            }
        }
    }

    return res;
}
// @lc code=end

