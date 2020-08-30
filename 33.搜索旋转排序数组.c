/*
 * @lc app=leetcode.cn id=33 lang=c
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start


int search(int* nums, int numsSize, int target){
    if (numsSize <= 0 || nums == NULL) {
        return -1;
    }
    int l = 0;
    int r = numsSize - 1;
    if (nums[0] > nums[numsSize - 1]) {
        //如果翻转了
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums[r]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (target >= nums[0]) {
            r = l;
            l = 0;
        } else {
            l = l;
            r = numsSize - 1;
        }
    }
    while (l < r) {
        int mid = l + r >> 1;
        if (nums[mid] >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (nums[l] == target) {
        return 1;
    }
    return -1;
}
// @lc code=end

