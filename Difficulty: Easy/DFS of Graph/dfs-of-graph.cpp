class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> ans = {0};
        vector<int> a = {0};
        vector<bool> b(adj.size(),0);
        b[0] = 1;
        int i = 0;
        while(a.size()!=0){
            if(b[i] == 0){
                a.push_back(i);
                ans.push_back(i);
                b[i]=1;
            }
            int j =0;
            while(j<adj[i].size() && b[adj[i][j]] == 1){
                j++;
            }
            if(j<adj[i].size()){
                i = adj[i][j];
            }
            else{
                a.pop_back();
                i = a[a.size()-1];
            }
        }
        return ans;
    }
};