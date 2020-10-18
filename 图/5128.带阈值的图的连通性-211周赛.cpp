class Solution {
public:
    vector<int> p;
    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        p.resize(n + 1);
        for (int i = 1; i <= n; i ++ ) p[i] = i;
        for (int d = threshold + 1; d <= n; d ++ )
            for (int i = d * 2; i <= n; i += d)
                p[find(d)] = p[find(i)];

        vector<bool> res;
        for (auto& q: queries) res.push_back(find(q[0]) == find(q[1]));

        return res;
    }
};
