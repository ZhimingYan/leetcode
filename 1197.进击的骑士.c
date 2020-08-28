typedef struct tagPos {
    int x;
    int y;
}Pos;

int g_dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int g_dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

int minKnightMoves(int x, int y){
    int board[310][310] = {0};
    x = abs(x);
    y = abs(y);

    if (x + y == 0) {
        return 0;
    }
    if ((x == 1) && y == 1) {
        return 2;
    }


    Pos queue[100000] = {0};
    int head = 0;
    int tail = 0;

    queue[0].x = 0;
    queue[0].y = 0;
    tail++;

    while (head != tail) {
        Pos tmp = queue[head++];
        for (int i = 0; i < 8; i++) {
            int dx = tmp.x + g_dx[i];
            int dy = tmp.y + g_dy[i];
            if (dx < 0 || dy < 0  ) {
                continue;
            }
            if (board[dx][dy] == 0) {
                board[dx][dy] = board[tmp.x][tmp.y] + 1;
                if (dx == x && dy == y) {
                    return board[dx][dy];
                }
                queue[tail].x = dx;
                queue[tail].y = dy;
                tail++;
            }
        }
    } 
    return -1;
}