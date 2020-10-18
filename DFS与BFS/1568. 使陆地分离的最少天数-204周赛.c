#define MAXNN 30

int g_state[MAXNN][MAXNN];
int **g_grid;
int g_row;
int g_col;
int g_dx[4] = {0, 1, 0, -1};
int g_dy[4] = {1, 0, -1, 0};

void dfs(int i, int j)
{
    g_state[i][j] = 1;
    for (int m = 0; m < 4; m++) {
        int x = i + g_dx[m];
        int y = j + g_dy[m];
        if (x < 0 || x >= g_row || y < 0 || y >= g_col || g_grid[x][y] == 0 || g_state[x][y] != 0) {
            continue;
        } 
        dfs(x, y);
    }
}

bool check()
{
    int count = 0;
    memset(g_state, 0, sizeof(g_state));
    for (int i = 0; i < g_row; i++) {
        for (int j = 0; j < g_col; j++) {
            if (!g_state[i][j] && g_grid[i][j] == 1) {
                dfs(i, j);
                count++; 
            }
        }
    }
    return count > 1;
}


int minDays(int** grid, int gridSize, int* gridColSize){
    memset(g_state, 0, sizeof(g_state));
    g_row = gridSize;
    g_col = gridColSize[0];
    g_grid = grid;

    int count = 0;
    for (int i = 0; i < g_row; i++) {
        for (int j = 0; j < g_col; j++) {
            if ( g_grid[i][j] == 1) {
                count++; 
            }
        }
    }
    if (count == 1) {
        return 1;
    }

    if (check()) {
        return 0;
    }
    for (int i = 0; i < g_row; i++) {
        for(int j = 0; j < g_col; j++) {
            if (g_grid[i][j]) {
                g_grid[i][j] = 0;
                if(check()) return 1;
                g_grid[i][j] = 1;
            }
        }
    }
    return 2;
}