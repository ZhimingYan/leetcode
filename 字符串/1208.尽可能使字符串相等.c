/*
 * @lc app=leetcode.cn id=1208 lang=c
 *
 * [1208] 尽可能使字符串相等
 */

// @lc code=start


int GetMax(int a , int b) {
    if (a >= b) {
        return a;
    }

    return b;
}
int equalSubstring(char * s, char * t, int maxCost){
    int len = strlen(s);
    int slow = 0;
    int fast = 0;
    int costCnt = 0;
    int dist = 0;

    while (slow <= fast && fast < len) {
        costCnt += abs(s[fast] - t[fast]);
        if (costCnt > maxCost) {
            costCnt -=  abs(s[slow] - t[slow]);
            slow++;
        }
        dist = GetMax(dist, fast - slow + 1);
        fast++;
        
    }

    return dist;
}
// @lc code=end

