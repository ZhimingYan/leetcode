/*
 * @lc app=leetcode.cn id=198 lang=c
 *
 * [198] 打家劫舍
 */

// @lc code=start
#define MAXLEN 201

int GetMax(int a, int b)
{
    return a > b? a : b;
}

int rob(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) {
        return 0;
    }
    int dp[MAXLEN + 1] = {0};
    dp[1] = nums[0];
    for (int i = 2; i <= numsSize; i++) {
        dp[i] = GetMax(dp[i - 1], dp[i - 2] + nums[i - 1]);   
    }
    return dp[numsSize];
}
// @lc code=end

