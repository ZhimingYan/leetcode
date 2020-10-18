class Solution {
public:
    int numberOfSets(int n, int k) {
        const int mod = 1000000007;
        vector<vector<int>> f(n, vector<int>(k + 1, 0));
        vector<vector<int>> g(n, vector<int>(k + 1, 0));

        f[0][0] = 1;
        g[0][0] = 1;
        for (int i = 1; i < n; i++)
            for (int j = 0; j <= k; j++) {
                f[i][j] = f[i - 1][j];
                if (j > 0)
                    f[i][j] = (f[i][j] + g[i - 1][j - 1]) % mod;

                g[i][j] = (g[i - 1][j] + f[i][j]) % mod;
            }

        return f[n - 1][k];
    }
};

作者：wzc1995
链接：https://www.acwing.com/solution/content/22795/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。