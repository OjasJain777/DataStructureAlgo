class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<int> d(V, INT_MAX);
        vector<vector<vector<int>>> b(V);
        for(vector<int> x: edges){
            b[x[0]].push_back({x[1], x[2]});
            b[x[1]].push_back({x[0], x[2]});
        }
        d[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while(pq.size()>0){
            int u = pq.top().second;
            int j = pq.top().first;
            pq.pop();
            if (j > d[u]) continue;
            for(vector<int> x: b[u]){
                if(d[x[0]] > d[u] + x[1]){
                    d[x[0]] = d[u] + x[1];
                    pq.push({d[x[0]], x[0]});
                }
            }
        }
        return d;
    }
};