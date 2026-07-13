class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        vector<vector<bool>> v(n,vector<bool>(k+2,0));
        vector<vector<int>> d(n, vector<int>(k+2, INT_MAX));
        vector<vector<vector<int>>> adj(n);
        for(auto &y:flights){
            adj[y[0]].push_back({y[1],y[2]});
        }
        d[src][k+1]=0;
        q.push({0,src, k+1});
        while(!q.empty()){
            auto y= q.top();
            q.pop();
            int cd = y[0];
            int cn = y[1];
            int s = y[2];
            if(v[cn][s]==1){
                continue;
            }
            v[cn][s] =1;
            if(s==0){
                continue;
            }
            for(auto &x: adj[cn]){
                if(v[x[0]][s-1]==0 && d[x[0]][s-1] > cd + x[1]){
                    d[x[0]][s-1] = cd + x[1];
                    q.push({d[x[0]][s-1], x[0], s-1});
                }
            }
        }
        int ans =INT_MAX;
        for(int x: d[dst]){
            ans = min(ans, x);
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};