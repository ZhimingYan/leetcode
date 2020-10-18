/*
 * @lc app=leetcode.cn id=300 lang=c
 *
 * [300] 最长上升子序列
 */

// @lc code=start

int max(int a, int b){
    return a > b ? a : b;
}

int lengthOfLIS(int* nums, int numsSize){
    int res = 0;
    if(numsSize == 0){
        return res;
    }
    int *dp = (int *)malloc(numsSize * sizeof(int));
    for(int i = 0 ; i < numsSize; i++){
        dp[i] = 1;
    }
    for(int i = 0; i < numsSize; i++){
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    for(int i = 0; i < numsSize; i++){
        res = max(res,dp[i]);
    }
    return res;

}


// @lc code=end

