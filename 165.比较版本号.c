/*
 * @lc app=leetcode.cn id=165 lang=c
 *
 * [165] 比较版本号
 */

// @lc code=start

int compareVersion(char * version1, char * version2){
    int n = strlen(version1);
    int m = strlen(version2);
    int i = 0;
    int j = 0;
    while (i < n || j < m) {
        int x = i;
        int y = j;
        int sum1 = 0;
        int sum2 = 0;
        while (x < n && version1[x] != '.') {
            sum1 = sum1 * 10 + version1[x++] - '0';
        }
        while (y < m && version2[y] !=  '.') {
            sum2 = sum2 * 10 + version2[y++] - '0';
        }
        if (sum1 > sum2) {
            return 1;
        } else if (sum1 < sum2) {
            return -1;
        }
        i = x + 1;
        j = y + 1;
    }
    return 0;
}


// @lc code=end

