class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        queue<int> a;
        vector<int> ans;
        vector<bool> v(adj.size(),0);
        a.push(0);
        v[0]=1;
        while(a.size()>0){
            int c = a.front();
            a.pop();
            ans.push_back(c);
            for(int x : adj[c]){
                if(v[x]!=0){
                    continue;
                }
                v[x] = 1;
                a.push(x);
            }
        }
        return ans;
    }
};