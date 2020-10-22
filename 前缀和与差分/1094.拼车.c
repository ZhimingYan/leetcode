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


#define MAXLEN 10000
int dff[MAXLEN + 1];
int sum[MAXLEN + 1];

void Insert(int l, int r, int c) {
    dff[l] += c;
    dff[r+1] -= c;
    
}

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){
    memset(dff, 0, sizeof(dff));
    
    for (int i = 0; i < tripsSize; i++) {
        Insert(trips[i][1], trips[i][2] - 1, trips[i][0]);
    }
    
    sum[0] = 0;
    for (int i = 1; i <= MAXLEN; i++) {
        sum[i] = sum[i - 1] + dff[i - 1];
        if (sum[i] > capacity) {
            return false;
        }
    }
    return true;
}

// @lc code=end

