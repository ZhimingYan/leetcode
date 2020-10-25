#define MAXLEN 101
int g_mark[MAXLEN][MAXLEN];
int g_dx[4] = {1, -1, 0, 0};
int g_dy[4] = {0, 0, -1, 1};
int g_c;
int g_r;


bool dfs(int **A, int x, int y, int d)
{
    if (x == g_r -1 && y == g_c - 1) {    
        return true;
    }
    g_mark[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int dx = g_dx[i] + x;
        int dy = g_dy[i] + y;

        if (dx >= 0 && dx < g_r && dy >= 0 && dy < g_c && g_mark[dx][dy] == 0 && d >= abs(A[dx][dy] - A[x][y])) {
            if (dfs(A, dx, dy, d)) {
                return true;
            }
        }
    }

    return false;
}

int minimumEffortPath(int** heights, int heightsSize, int* heightsColSize){
    g_r = heightsSize;
    g_c = heightsColSize[0];
   
    int l = 0, r = 1e6, mid, ans = 0;
    while(l <= r)
    {
        mid = l + ((r-l)>>1);
        memset(g_mark, 0, sizeof(g_mark));
        if(dfs(heights, 0, 0, mid)){
            r = mid-1;
            ans = mid;
        }
        else{
            l = mid+1;
        }    
    }
    return ans;
}