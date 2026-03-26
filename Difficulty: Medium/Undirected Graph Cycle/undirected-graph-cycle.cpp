void bfs(vector<vector<int>> &adj, vector<bool> &v, queue<pair<int, int>> &q, int &ans){
    while(q.size()>0){
        auto y = q.front();
        int c = y.first;
        int f = y.second;
        q.pop();
        for(int k =0; k<adj[c].size();k++){
            if(v[adj[c][k]]==0){
                q.push({adj[c][k], c});
                v[adj[c][k]]=1;
            }
            else if(adj[c][k]!=f){
                ans*=0;
                return;
            }
        }
    }
}
class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(int i =0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> v(V,0);
        int ans =1;
        for(int i =0; i<V;i++){
            if(v[i]==0){
                queue<pair<int, int>> q;
                q.push({i, i});
                v[i]=1;
                bfs(adj, v, q, ans);
            }
        }
        return (ans+1)%2;
    }
};