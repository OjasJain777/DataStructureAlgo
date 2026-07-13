class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> w(n, 0);
        long long mod = 1e9 + 7;
        vector<long long> d(n, LLONG_MAX);
        d[0] = 0;
        vector<vector<vector<long long>>> adj(n);
        for (auto& x : roads) {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        w[0] = 1;
        priority_queue<vector<long long>, vector<vector<long long>>,
                       greater<vector<long long>>>
            q;
        q.push({0, 0});
        while (!q.empty()) {
            auto y = q.top();
            long long cd = y[0];
            long long cn = y[1];
            q.pop();
            if (cd > d[cn]) {
                continue;
            }
            for (auto& x : adj[cn]) {
                if (d[x[0]] > cd + x[1]) {
                    d[x[0]] = cd + x[1];
                    w[x[0]] = w[cn];
                    q.push({d[x[0]], x[0]});
                } else if (d[x[0]] == cd + x[1]) {
                    w[x[0]] = (w[x[0]] + w[cn]) % mod;
                }
            }
        }
        return w[n - 1];
    }
};