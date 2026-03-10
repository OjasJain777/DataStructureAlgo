class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        queue<int> a;
        vector<int> ans;
        vector<bool> b(adj.size(), 0);
        a.push(0);
        b[0]= 1;
        while(a.size()>0){
            int i = a.front();
            a.pop();
            ans.push_back(i);
            for(int x: adj[i]){
                if(b[x] == 0){
                    a.push(x);
                    b[x] = 1;
                }
            }
        }
        return ans;
    }
};