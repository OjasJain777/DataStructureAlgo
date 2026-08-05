class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &y: edges){
            adj[y[0]].push_back(y[1]);
        }
        queue<int> q;
        q.push(k);
        vector<bool> v(n,0);
        v[k]=1;
        while(!q.empty()){
            auto y = q.front();
            q.pop();
            for(auto x: adj[y]){
                if(v[x]==0){
                    v[x]=1;
                    q.push(x);
                }
            }
        }
        bool t = 0;
        for(auto &y: edges){
            if(v[y[0]]==0 && v[y[1]]==1){
                t=1;
            }
        }
        vector<int> ans;
        if(t){
            for(int i =0 ; i<n;i++){
                ans.push_back(i);
            }
        }
        else{
            for(int i = 0; i<n;i++){
                if(v[i]==0){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};