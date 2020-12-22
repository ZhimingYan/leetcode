### DFS-岛屿类问题解决思路

常见的背包问题有

**1、岛屿个数与问题**

[200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)

**2、岛屿面积问题**

 [695. 岛屿的最大面积](https://leetcode-cn.com/problems/max-area-of-island/)

**3、包围问题**

 [130. 被围绕的区域](https://leetcode-cn.com/problems/surrounded-regions/)

[1254. 统计封闭岛屿的数目](https://leetcode-cn.com/problems/number-of-closed-islands/)

**核心模板**

~~~cpp
/* 满水填充算法 */    
int dx[4] = {0 , 0, 1, -1};
    int dy[4] = {1 , -1, 0, 0};
    int n;
    int m;
    int count;
    void dfs(vector<vector<int>> &grid, int i , int j) {
        if (grid[i][j] != 1) {
            return;
        }
        grid[i][j] = -1;
        count ++;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && y >= 0 && x < n && y < m) {
                dfs(grid, x, y);
            }    
        }
    }
~~~

**参考链接**

1. [leetcode 与岛屿有关的问题总结](https://www.acwing.com/blog/content/3750/)
