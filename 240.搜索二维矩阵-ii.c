/*
 * @lc app=leetcode.cn id=240 lang=c
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
   for (int i = 0, j = matrixColSize - 1; i < matrixRowSize &&  j >= 0 ; ) {
           if (matrix[i][j] == target) {
               return true;
           } else if (matrix[i][j] < target) {
               i++;
           } else {
               j--;
           }
   }
   return false;
}
// @lc code=end

