/*
 * @lc app=leetcode.cn id=934 lang=c
 *
 * [934] 最短的桥
 */

// @lc code=start


int g_dx[4] = {0, 1, 0, -1};
int g_dy[4] = {-1, 0, 1, 0};
int g_r;
int g_c;

typedef struct tagPos
{
    int x;
    int y;
}Pos;

Pos g_queue[10010];
int g_head;
int g_tail;

void dfs(int **A, int x, int y)
{
    if (A[x][y] == 0 || A[x][y] == 2) {
        return;
    }
    g_queue[g_tail].x = x;
    g_queue[g_tail].y = y;
    g_tail++;
    A[x][y] = 2;
    for (int i = 0; i < 4; i++) {
        int dx = g_dx[i] + x;
        int dy = g_dy[i] + y;
        if (dx < 0 || dx >= g_r || dy < 0 || dy >= g_c) {
            continue;
        }
        dfs (A, dx, dy);
    }
}



int shortestBridge(int** A, int ASize, int* AColSize){
    g_r = ASize;
    g_c = AColSize[0];
    g_head = 0;
    g_tail = 0;
    memset(g_queue, 0, sizeof(g_queue));

    for (int i = 0; i < g_r * g_c; i++) {
        if (A[i / g_r][i % g_c] == 1) {
            dfs(A, i / g_r, i % g_c);
            break;
        }
    }

    int step = 0;
    while (g_head <= g_tail) {
        int k = g_tail - g_head;
        for (int j = 0; j < k; j++) {
            Pos temp = g_queue[g_head++];
            for (int i = 0; i < 4; i++) {
                int dx = g_dx[i] + temp.x;
                int dy = g_dy[i] + temp.y;
                if (dx < 0 || dx >= g_r || dy < 0 || dy >= g_c) {
                    continue;
                }
                if (A[dx][dy] == 2) {
                    continue;
                }
                if (A[dx][dy] == 0) {
                    A[dx][dy] = 2;
                    g_queue[g_tail].x = dx;
                    g_queue[g_tail].y = dy;
                    g_tail++;
                
                }
                if (A[dx][dy] == 1) {
                    return step;
                }
            }  
        }
        step++;        
    }
    return step;
}
// @lc code=end

