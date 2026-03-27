class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> c(V);
        vector<int> ans;
        queue<int> q;
        vector<vector<int>> adj(V);
        for(int i =0; i< edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            c[edges[i][1]]++;
        }
        for(int i =0; i<c.size();i++){
            if(c[i]==0){
                q.push(i);
            }
        }
        while(q.size()>0){
            int n = q.front();
            q.pop();
            ans.push_back(n);
            for(int j =0; j<adj[n].size();j++){
                c[adj[n][j]]--;
                if(c[adj[n][j]]==0){
                    q.push(adj[n][j]);
                }
            }
        }
        return ans;
    }
};