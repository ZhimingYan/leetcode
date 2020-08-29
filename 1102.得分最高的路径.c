//超时
#define MaxNN 100
int g_mark[MaxNN][MaxNN];
int g_dx[4] = {1, -1, 0, 0};
int g_dy[4] = {0, 0, -1, 1};
int g_r;
int g_c;
int g_maxScore;

void dfs(int **A, int x, int y, int score)
{
    if (x == g_r -1 && y == g_c - 1) {
        if (g_maxScore < score) {
            g_maxScore = score;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int dx = g_dx[i] + x;
        int dy = g_dy[i] + y;

        if (dx >= 0 && dx < g_r && dy >= 0 && dy < g_c && g_mark[dx][dy] == 0) {
            if (A[dx][dy] <= g_maxScore) {
                continue;
            }
            g_mark[dx][dy] = 1;
            int newScore = score > A[dx][dy] ? A[dx][dy] : score;
            dfs(A, dx, dy, newScore);
            g_mark[dx][dy] = 0;
        }
    }
}

int maximumMinimumPath(int** A, int ASize, int* AColSize){
    if (A == NULL || ASize <= 0 || AColSize == NULL || AColSize[0] <= 0) {
        return -1;
    }
    g_r = ASize;
    g_c = AColSize[0];
    g_maxScore = -1;
    memset(g_mark, 0, MaxNN * MaxNN);
    dfs(A, 0, 0, A[0][0]);
    return g_maxScore;
}