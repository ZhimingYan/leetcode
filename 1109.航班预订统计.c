/*
 * @lc app=leetcode.cn id=1109 lang=c
 *
 * [1109] 航班预订统计
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define TOTAL_FLITE 200010

int g_flite[TOTAL_FLITE];

void Init() {
    for (int i = 0; i < TOTAL_FLITE; i++) {
        g_flite[i] = 0;
    }
}

int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize){
    //Init();
    memset(g_flite, 0, sizeof(g_flite));
    int*res = (int *)malloc(n * sizeof(int));
    if (res == NULL) {
        return NULL;
    }
    memset(res, 0, sizeof(int));
    for (int i = 0; i < bookingsSize; i++) {
        g_flite[bookings[i][0]] += bookings[i][2];
        g_flite[bookings[i][1] + 1] -= bookings[i][2];
    }
    res[0] = g_flite[1];
    for (int j = 1; j < n; j++){
        res[j] =res[j - 1] + g_flite[j + 1];
    }
    *returnSize = n;
    return res;
}

// @lc code=end

