// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(V);
        vector<int> ans(V,-1);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        ans[0]=0;
        for(auto y: edges){
            adj[y[0]].push_back({y[1], y[2]});
        }
        q.push({0,0});
        while(q.size()!=0){
            auto z = q.top();
            q.pop();
            int d = z[0];
            int c = z[1];
            for(vector<int> x: adj[c]){
                if(ans[x[0]]==-1 || ans[x[0]] > d + x[1]){
                    ans[x[0]] = d + x[1];
                    q.push({ans[x[0]], x[0]});
                }
            }
        }
        return ans;
    }
};
