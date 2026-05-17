class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<vector<int>>> adj(V);
        vector<int> ans(V, -1);
        vector<bool> v(V,0);
        ans[src]=0;
        for(auto y: edges){
            adj[y[0]].push_back({y[1], y[2]});
            adj[y[1]].push_back({y[0], y[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, src});
        while(q.size()!=0){
            auto z = q.top();
            int c = z[1];
            int d = z[0];
            q.pop();
            if(v[c]==0){
                for(auto x: adj[c]){
                    if(ans[x[0]]==-1 || ans[x[0]]> x[1]+ d){
                        ans[x[0]]= x[1]+ d;
                        q.push({ans[x[0]], x[0]});
                    }
                }
            }
            v[c]=1;
        }
        return ans;
    }
};