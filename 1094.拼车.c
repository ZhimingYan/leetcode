/*
 * @lc app=leetcode.cn id=1094 lang=c
 *
 * [1094] 拼车
 */

// @lc code=start


#define N 1010
int g_pos[N];

void InitPos() {
    for (int i = 0 ; i < N; i ++) {
        g_pos[i] = 0;
    }
} 

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){
    InitPos();
    for (int i = 0; i < tripsSize; i++) {
        g_pos[trips[i][1]] += trips[i][0];
        g_pos[trips[i][2]] -= trips[i][0];
    }
    for (int i = 0; i < N; i ++){
        capacity -= g_pos[i];
        if (capacity < 0) {
            return false;
        }
    }
    return true;
}


// @lc code=end

