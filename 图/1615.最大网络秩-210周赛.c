/*
参考图的入度与出度
定义一个cities[]数组，cities[i]保存城市i的线路数
定义一个map[][]数组，map[i][j]=1表示城市i和城市j间有线路，map[i][j]=0表示城市i和城市j间无线路
遍历数组roads
- cities[roads[i][0]]++
- cities[roads[i][1]]++
- map[roads[i][0]][roads[i][1]] = 1
- map[roads[i][1]][roads[i][0]] = 1 //map[i][j],map[j][i]都要置为1
二重循环---res = cities[i] + cities[j] - map[i][j]

作者：bei-liang-3
链接：https://leetcode-cn.com/problems/maximal-network-rank/solution/shu-ju-jie-gou-tu-5-by-bei-liang-3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

int maximalNetworkRank(int n, int** roads, int roadsSize, int* roadsColSize){
    int *cities = malloc(sizeof(int) * n);
    memset(cities, 0, sizeof(int) *n);
    int **map = malloc(sizeof(int *) *n);
    for(int i = 0; i < n; i++) {
        map[i] = malloc(sizeof(int) *n);
        for(int j = 0; j < n; j++) {
            map[i][j] = 0;
        }
    }

    for(int i = 0; i < roadsSize; i++) {
        int *r = roads[i];
        int c1 = r[0];
        int c2 = r[1];
        cities[c1] += 1;
        cities[c2] += 1;
        map[c1][c2] = 1;
        map[c2][c1] = 1; //这里也要加入
    }

    int result = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i != j) {
                int rs = cities[i] + cities[j] - map[i][j];                
                if (rs > result) {                    
                    result = rs;
                }
            }
        }
    }

    return result;
}

作者：yuan-yuan-mu-gong
链接：https://leetcode-cn.com/problems/maximal-network-rank/solution/can-kao-tu-de-ru-du-he-chu-du-by-yuan-yuan-mu-gong/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。