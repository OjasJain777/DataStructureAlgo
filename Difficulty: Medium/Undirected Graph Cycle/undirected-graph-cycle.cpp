class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<bool> v(V,0);
        vector<vector<int>> adj(V);
        stack<pair<int, int>> s;
        for(int i =0; i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i =0; i<V; i++){
            if(v[i]==1){
                continue;
            }
            s.push({i,i});
            v[i]=1;
            while(s.size()>0){
                auto y = s.top();
                int c = y.first;
                int f = y.second;
                if(adj[c].size()==0){
                    s.pop();
                    continue;
                }
                else if(v[adj[c][adj[c].size()-1]]==0){
                    s.push({adj[c][adj[c].size()-1], c});
                    v[adj[c][adj[c].size()-1]]=1;
                }
                else if(f != adj[c][adj[c].size()-1]){
                    return 1;
                }
                adj[c].pop_back();
            }
        }
        return 0;
    }
};