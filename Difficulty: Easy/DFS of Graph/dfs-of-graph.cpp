class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        stack<int> a;
        vector<bool> v(adj.size(),0);
        vector<int> ans = {0};
        a.push(0);
        v[0]=1;
        while(a.size()>0){
            int c = a.top();
            int h = 0;
            for(int x: adj[c]){
                if(v[x]==0){
                    a.push(x);
                    v[x]=1;
                    ans.push_back(x);
                    h = 1;
                    break;
                }
            }
            if(h==0){
                a.pop();
            }
        }
        return ans;
    }
};