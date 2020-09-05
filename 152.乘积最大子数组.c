/*
 * @lc app=leetcode.cn id=152 lang=c
 *
 * [152] 乘积最大子数组
 */

// @lc code=start


int GetMin(int a, int b)
{
    return a < b? a : b;
}

int GetMax(int a, int b)
{
    return a > b? a : b;
}

int maxProduct(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    } 
    if (numsSize == 1) {
        return nums[0];
    }
    int dp = nums[0];
    int maxDp = nums[0];
    int minDp = nums[0];

    for (int i = 1; i < numsSize; i++) {
        int t = maxDp;
        maxDp = GetMax(GetMax(maxDp * nums[i], nums[i]), minDp * nums[i]);
        minDp =  GetMin(GetMin(t * nums[i], nums[i]), minDp * nums[i]);
        dp = GetMax(maxDp, dp);
    }
    return dp;
}
// @lc code=end

