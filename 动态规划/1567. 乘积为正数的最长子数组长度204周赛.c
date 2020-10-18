#define MAXLEN 100001

int g_f[MAXLEN];
int g_g[MAXLEN];

int Max(int a , int b) {
    return a > b? a : b;
}

int getMaxLen(int* nums, int numsSize){
    memset(g_f, 0, sizeof(g_f));
    memset(g_g, 0, sizeof(g_g));
    int res = 0;
    if (nums[0] > 0) {
        g_f[0] = 1;
        g_g[0] = 0;
        res = 1;
    } else if (nums[0] < 0) {
        g_g[0] = 1;
        g_f[0] = 0;
    }
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == 0) {
            g_f[i] = 0;
            g_g[i] = 0;
        } else if (nums[i] > 0) {
            g_f[i] = g_f[i - 1] + 1;
            if (g_g[i - 1] != 0) {
                g_g[i] = g_g[i - 1] + 1;
            }   
        } else {
            if (g_g[i - 1] != 0) {
                g_f[i] = g_g[i - 1] + 1;
            }
            g_g[i] = g_f[i - 1] + 1;
        }
        res = res > g_f[i]? res : g_f[i];
    }
    return res;
}