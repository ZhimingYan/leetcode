/*
 * @lc app=leetcode.cn id=200 lang=c
 *
 * [200] 岛屿数量
 */

// @lc code=start
#define MAX_NN 100
int g_father[MAX_NN];
int g_fatherLen;

/* 初始化，所有的节点的祖宗节点都指向自己 */
void Init()
{
    for (int i = 0; i < g_fatherLen; i++) {
        g_father[i] = i;
    }
}

int Find(int n)
{
    /* 如果指向自己，说明自己就是祖宗节点 */
    if (g_father[n] == n) {
        return n;
    }
    /*  否则就向上寻找自己的祖宗节点 */
    g_father[n] = Find(g_father[n]);
    return g_father[n];
} 

void Union(int a, int b) 
{
    /* 找到a和b的祖宗节点 */
    int aFather = Find(a);
    int bFather = Find(b);
    /* 将两者连接起来 */
    g_father[aFather] = bFather;
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridSize == 0 || gridColSize == NULL) {
        return 0;
    }
    memset(g_father, 0, sizeof(g_father));
    g_fatherLen = gridSize * gridColSize[0];
    Init();

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int m = gridSize;
    int n = gridColSize[0];
    for (int i = 0; i < m*n; i++) {
        int current_x = i / m;
        int current_y = i % m;
        if (grid[current_x][current_y] == '1') {
            for (int k = 0; k < 4; k++) {
                int x = current_x + dx[k];
                int y = current_y + dy[k];
                if (x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }
                if (grid[x][y] == '1') {
                    Union(i, x * m + y);
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < g_fatherLen; i++) {
        if (i == Find(i)) {
            count++;
        }
    }

    return count;
}
// @lc code=end

