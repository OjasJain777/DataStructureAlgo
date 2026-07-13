class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Use vector<pair<int, int>> instead of vector<vector<long long>>
        // adj[u] will store {v, time}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        int mod = 1e9 + 7;

        // Min-heap storing pairs of {distance, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            // Using C++17 structured binding for cleaner syntax
            auto [current_dist, u] = pq.top(); 
            pq.pop();

            // Lazy deletion step
            if (current_dist > dist[u]) continue;

            for (const auto& [v, time] : adj[u]) {
                if (dist[v] > current_dist + time) {
                    // Strictly shorter path found
                    dist[v] = current_dist + time;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                } else if (dist[v] == current_dist + time) {
                    // Equal shortest path found
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};