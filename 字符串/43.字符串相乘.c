/*
 * @lc app=leetcode.cn id=43 lang=c
 *
 * [43] 字符串相乘
 */

// @lc code=start

char * MultiplyByOne(char * nums, char c) {
    int len = strlen(nums);
    char * res = (char*)malloc((len+1) * sizeof(char));
    memset(res, 0, sizeof(res));
    int add = 0;
    for(int i = len - 1; i >= 0; i--) {
        int a = nums[i] - '0';
        int b = c - '0';
        int tmp = a * b;
        res[i + 1] = (tmp % 10) + '0' + add;
        add = tmp / 10 + '0';
    }
    return res;
}

char * AddByTwo(char *nums1, char * nums2) {
    int len1 = strlen(nums1);
    int len2 = strlen(nums2);
    if (len1 > len2) {
        len1 = len2;
        char *tmp = nums1;
        nums1 = nums2;
        nums2 = tmp;
    }

    char * res = (char*) malloc((len1 + 1))

    for (int i = len1; i >= 0; i--) {

    }
}

char * multiply(char * num1, char * num2){

}


// @lc code=end

