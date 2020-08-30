/*
 * @lc app=leetcode.cn id=213 lang=c
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#define MAXLEN 2000

int GetMax(int a, int b) 
{
    return a > b? a : b;
}
int rob(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) {
        return 0;
    }
    if ( numsSize == 1) {
        return nums[0];
    }
    int dp1[MAXLEN + 1] = {0};
    int dp2[MAXLEN + 1] = {0};

    //第一个不选
    dp1[1] = nums[0];
    for (int i = 2; i <= numsSize - 1; i++) {
        dp1[i] = GetMax(dp1[i-1], dp1[i - 2] + nums[i - 1]);
    }
    //第一个选
    dp2[numsSize - 1] = nums[numsSize - 1];
    for (int i = numsSize - 2; i; i--) {
        dp2[i] = GetMax(dp2[i+1], dp2[i + 2] + nums[i]);
    }
    return GetMax(dp1[numsSize - 1], dp2[1]);
}


// @lc code=end

