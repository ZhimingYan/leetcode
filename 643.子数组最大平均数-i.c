/*
 * @lc app=leetcode.cn id=643 lang=c
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start


double GetMax(double a, double b)
{
    return a > b? a : b;
}

double findMaxAverage(int* nums, int numsSize, int k){
    if (numsSize == 0) {
        return 0;
    }
    if (numsSize == 1) {
        return nums[0];
    }
    double res = 0.0;
    for (int i = 0; i < k ; i++) {
        res += nums[i];
    }
    double res2 = res;
    for (int i = k - 1; i < numsSize; i++) {
        int s = i - k + 1;
        if(i + 1 < numsSize) {
           res = res + nums[i+1] - nums[s];
           res2 = GetMax(res, res2);
        }
    }
    return res2/k;
}

// @lc code=end

