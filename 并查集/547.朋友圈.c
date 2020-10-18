/*
 * @lc app=leetcode.cn id=547 lang=c
 *
 * [547] 朋友圈
 */

// @lc code=start
#define MAX_NN 200
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

int findCircleNum(int** M, int MSize, int* MColSize){
    g_fatherLen = MSize;
    Init();

    for (int i = 0; i < MSize; i++) {
        for (int j = 0; j < MSize; j++) {
            if (M[i][j] == 1) {
                Union(i, j);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < MSize; i++) {
        if (g_father[i] == i) {
            res++;
        }
    }
    *MColSize = MSize;
    return res;
}

// @lc code=end

