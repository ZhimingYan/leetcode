/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAXLEN 101

int sum[MAXLEN][MAXLEN];

int** matrixBlockSum(int** mat, int matSize, int* matColSize, int K, int* returnSize, int** returnColumnSizes){
    int m = matSize;
    int n = matColSize[0];
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];// 构建二维前缀和的方法
            printf("  %d\n", sum[i][j]);
        }
        printf("\n");
    }      
     int **res = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++) {
        res[i] = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            int x1, x2, y1, y2;
            x1 = i - K < 0? 0 : i - K;
            x2 = i + K >= m? m - 1 : i + K;
            y1 = j - K < 0 ? 0 : j - K;
            y2 = j + K >= n ? n - 1 : j + K;   
            res[i][j] = sum[x2 + 1][y2 + 1] + sum[x1][y1] - sum[x2 + 1][y1] - sum[x1][y2 + 1];//二维前缀和需要注意
        }
    } 
    

    //需要返回二维数组的处理
    *returnSize = m;
    *returnColumnSizes = (int *)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i ++) {
       (*returnColumnSizes)[i] = n;//注意这里有符号优先级的问题
    }
    return res;
}