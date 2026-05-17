class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto y: edges){
            adj[y[0]].push_back(y[1]);
            adj[y[1]].push_back(y[0]);
        }
        vector<bool> v(V,0);
        for(int i =0; i<V;i++){
            if(v[i]==0){
                queue<pair<int, int>> q;
                q.push({i,-1});
                v[i]=1;
                while(q.size()!=0){
                    int n = q.size();
                    for(int k=0; k<n;k++){
                        auto [c,z] = q.front();
                        q.pop();
                        for(auto j:adj[c]){
                            if(v[j]==1 && j!=z){
                                return 1;
                            }
                            else if (v[j]==0){
                                q.push({j, c});
                                v[j]=1;
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
};