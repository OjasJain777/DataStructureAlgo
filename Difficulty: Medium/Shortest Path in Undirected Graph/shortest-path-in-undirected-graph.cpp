class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<vector<int>> adj(V);
        vector<int> ans(V, -1);
        for(auto y : edges){
            adj[y[0]].push_back(y[1]);
            adj[y[1]].push_back(y[0]);
        }
        ans[src]= 0;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, src});
        while(q.size()!=0){
            auto [d, c] = q.top();
            q.pop();
            for(int x: adj[c]){
                if(ans[x]==-1 || d+1<ans[x]){
                    ans[x] = d+1;
                    q.push({ans[x], x});
                }
            }
        }
        return ans;
    }
};
