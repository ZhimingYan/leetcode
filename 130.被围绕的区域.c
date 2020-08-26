/*
 * @lc app=leetcode.cn id=130 lang=c
 *
 * [130] 被围绕的区域
 */

// @lc code=start
#include <stdbool.h>

#include <stdbool.h>

static void dfs(char **board, int boardSize, int* boardColSize, int i, int j) 
{
    if (i < 0 || i >= boardSize || j < 0 || j >= boardColSize[0] || board[i][j] != 'O' ) {
        return;
    }
    board[i][j] = '*';
    dfs(board, boardSize, boardColSize, i - 1, j);
    dfs(board, boardSize, boardColSize, i + 1, j);
    dfs(board, boardSize, boardColSize, i, j + 1);
    dfs(board, boardSize, boardColSize, i, j - 1);

}

void solve(char** board, int boardSize, int* boardColSize){
    if (boardSize == 0) {
        return;
    }
    for (int i = 0; i < boardSize; i++) {
        dfs(board, boardSize, boardColSize, i, 0);
        dfs(board, boardSize, boardColSize, i, boardColSize[0] - 1);
    }
    for (int j = 0; j < boardColSize[0]; j++) {
        dfs(board, boardSize, boardColSize, boardSize - 1, j);
        dfs(board, boardSize, boardColSize, 0, j);
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == '*') {
                board[i][j] = 'O';
            }
        }
    }

}
// @lc code=end

